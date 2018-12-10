#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\TCCTasks\Task2Listener.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace Task2;

namespace TestTCCTest
{
	TEST_CLASS(TaskTest2)
	{
	public:
		TEST_METHOD(Receive_gives_back_input)
		{
			Task2Listener listener(1);
			char input[] = { '\0' };
			auto receiveResult = listener.Receive(input);

			Assert::AreEqual(std::string("\0"), receiveResult);

			listener.Stop();
		}

		TEST_METHOD(Receive_z_stops_the_threads)
		{
			Task2Listener listener(1);
			char input[] = { 'z' };
			auto receiveResult = listener.Receive(input);

			Assert::IsTrue(listener.IsStopped());
		}

		TEST_METHOD(Receive_results_number_of_calls)
		{
			Task2Listener listener(2);
			char input[] = { '\0' };
			auto receiveResult = listener.Receive(input);

			input[0] = { 'z' };
			receiveResult = listener.Receive(input);

			auto stat = listener.Result();
			Assert::IsTrue(stat.size() == 2);
			Assert::IsTrue(stat[0] == 1);
			Assert::IsTrue(stat[1] == 0);
		}

		TEST_METHOD(Receive_works_on256_thread)
		{
			Task2Listener listener(256);
			char input[] = { '\0' };
			auto receiveResult = listener.Receive(input);

			input[0] = { 'z' };
			receiveResult = listener.Receive(input);

			auto stat = listener.Result();
			Assert::IsTrue(stat.size() == 256);
			Assert::IsTrue(stat[0] == 1);
			Assert::IsTrue(stat[1] == 0);
		}

	};
}