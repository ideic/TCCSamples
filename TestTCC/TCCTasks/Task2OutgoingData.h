#pragma once
#include <string>
#include <vector>
#include <mutex> 
#include <condition_variable>

namespace Task2 {
	class Task2OutgoingData
	{
	public:
		Task2OutgoingData();
		~Task2OutgoingData();

		std::string  Pop();
		void Push(std::string value);

	private:
		std::vector<std::string> data;
		std::mutex mtx;
		std::condition_variable cv;
	};

}