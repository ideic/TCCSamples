#include "stdafx.h"
#include "Task2OutgoingData.h"
#include <algorithm>
namespace Task2 {
	Task2OutgoingData::Task2OutgoingData()
	{
	}


	Task2OutgoingData::~Task2OutgoingData()
	{
	}

	std::string Task2OutgoingData::Pop()
	{
		//std::lock_guard<std::mutex> lck(mtx);
		std::unique_lock<std::mutex> lck(mtx);
		cv.wait(lck, [&] {return data.size() > 0; });

		auto result = data.front();
		auto newend = std::remove(begin(data), end(data), result);
		data.erase(newend, end(data));

		return result;
	}

	void Task2OutgoingData::Push(std::string value)
	{
		std::lock_guard<std::mutex> lck(mtx);
		data.emplace_back(value);
		cv.notify_all();
	}
}