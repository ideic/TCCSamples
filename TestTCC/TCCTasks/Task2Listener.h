#pragma once
#include <string>
#include <vector>
#include <map>
#include "Task2Processor.h"

namespace Task2 {
	class Task2Listener
	{
	public:
		Task2Listener();
		Task2Listener(int underlyingProcessors);
		~Task2Listener();
		std::string Receive(char recvbuf[]);
		void Stop();

		bool IsStopped();
		std::map<int, int> Result();
	private:
		std::vector<std::shared_ptr<Task2Processor>> processors;
		Task2IncomingData incomingData;
		Task2OutgoingData outgoingData;
		bool isStopped;
	};
}
