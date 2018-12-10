#include "stdafx.h"
#include "Task2Processor.h"
#include <utility>
namespace Task2 {
	Task2Processor::Task2Processor(int key) :key(key), stopped(false), result(std::pair<int, int>(key, 0))
	{
	}


	Task2Processor::~Task2Processor()
	{
	}

	void Task2Processor::Start(Task2IncomingData & incomingData, Task2OutgoingData & outgoingData)
	{
		stopped = false;
		incomingData.SubscribeForIncomingDataEvent(std::pair<int, std::function<void()>>(key, [this]() { Task2Processor::DataArrived(); }));
		
		thread = std::thread([&]()
		{
			while (!stopped) {
				if (incomingData.TryMoveValue(key)) {
					result.second++;
					char s[] = { (char)key, '\0' };
					outgoingData.Push(std::string(s));
				}
				else {
					std::unique_lock<std::mutex> lck(mtx);
					cv.wait(lck);
					lck.unlock();
				}
			}
		});
	}
	void Task2Processor::Stop()
	{
		cv.notify_all();
		stopped = true;
		thread.join();
	}

	std::pair<int, int> Task2Processor::Result()
	{
		return result;
	}

	void Task2Processor::DataArrived()
	{
		cv.notify_all();
	}
}
