#pragma once
#include "Task2IncomingData.h"
#include "Task2OutgoingData.h"
#include <mutex> 
#include <condition_variable>

namespace Task2 {
	class Task2Processor
	{
	public:
		Task2Processor(int key);
		~Task2Processor();
		void Start(Task2IncomingData &incomingData, Task2OutgoingData &outgoingData);
		void Stop();
		std::pair<int, int> Result();
	private:
		void DataArrived();
		int key;
		std::mutex mtx;
		std::condition_variable cv;
		bool stopped;
		std::pair<int, int> result;
		std::thread thread;
	};
}
