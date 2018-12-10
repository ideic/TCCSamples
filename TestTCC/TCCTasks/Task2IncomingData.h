#pragma once
#include <string>
#include <shared_mutex>
#include <map>
#include <vector>
namespace Task2 {
	class Task2IncomingData
	{
	public:
		Task2IncomingData();
		~Task2IncomingData();

		void Add(int input);
		bool TryMoveValue(int target);
		void SubscribeForIncomingDataEvent(std::pair<int, std::function<void()>> callback);
		void UnSubscribeFromIncomingDataEvent(int callbackKey);

	private:
		std::mutex mutex;

		std::vector<int> incomingData;
		std::map <int, std::function<void()>> subscribers;
	};
}
