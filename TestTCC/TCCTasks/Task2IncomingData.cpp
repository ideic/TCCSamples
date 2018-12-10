#include "stdafx.h"
#include "Task2IncomingData.h"
#include <algorithm>
namespace Task2 {
	Task2IncomingData::Task2IncomingData()
	{
	}


	Task2IncomingData::~Task2IncomingData()
	{
		incomingData.clear();
		subscribers.clear();
	}

	void Task2IncomingData::Add(int input)
	{
		std::lock_guard<std::mutex> lck(mutex);
		incomingData.push_back(input);
		std::for_each(begin(subscribers), end(subscribers), [](auto subscriber) {
			subscriber.second();
		});
	}

	bool Task2IncomingData::TryMoveValue(int target)
	{
		std::lock_guard<std::mutex> lck(mutex);
		auto found = find(begin(incomingData), end(incomingData), target);
		if (found != end(incomingData)) {
			incomingData.erase(found);
			return true;
		}

		return false;
	}

	void Task2IncomingData::SubscribeForIncomingDataEvent(std::pair<int, std::function<void()>> callback)
	{
		subscribers.insert(callback);
	}

	void Task2IncomingData::UnSubscribeFromIncomingDataEvent(int callbackKey)
	{
		auto found = subscribers.find(callbackKey);
		subscribers.erase(found);
	}
}