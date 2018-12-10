#include "stdafx.h"
#include "Task2Listener.h"
#include <utility>
namespace Task2 {
	Task2Listener::Task2Listener() :Task2Listener(0) {

	}

	Task2Listener::Task2Listener(int underlyingProcessors):isStopped(false)
	{

		for (int i = 0; i < underlyingProcessors; i++) {
			std::shared_ptr<Task2Processor> processor(new Task2Processor(i));
			processors.emplace_back(processor);

			processor.get()->Start(incomingData, outgoingData);
		}
	}


	Task2Listener::~Task2Listener()
	{
	}

	std::string Task2Listener::Receive(char recvbuf[])
	{
		if (recvbuf[0] == 'z') {
			Stop();
			return std::string();
		}
					
		incomingData.Add(recvbuf[0]);
		
		return outgoingData.Pop();
	}
	void Task2Listener::Stop()
	{
		for (auto processor : processors) {
			processor->Stop();
		}
		isStopped = true;
	}
	bool Task2Listener::IsStopped()
	{
		return isStopped;
	}
	std::map<int, int> Task2Listener::Result()
	{
		auto result = std::map<int, int>();
		for (auto processor : processors) {
			result.insert(processor->Result());
		}
		return result;
	}
}