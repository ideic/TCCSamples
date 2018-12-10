#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\TCCTasks\OperationVariator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace Task1;
namespace TestTCCTest
{
	TEST_CLASS(OperationVariatorTest)
	{
	public:
		TEST_METHOD(NextVariation_On1bit)
		{
			std::vector<bool> op = { false };
			auto result = ov.NextVariation(op);

			Assert::AreEqual(true, result);
			Assert::IsTrue(op[0]);
		}

		TEST_METHOD(NextVariation_On1bitOverflow)
		{
			std::vector<bool> op = { true };
			auto result = ov.NextVariation(op);

			Assert::AreEqual(false, result);
		}

		TEST_METHOD(NextVariation_On2bit00)
		{
			std::vector<bool> op = { false, false };
			auto result = ov.NextVariation(op);

			Assert::AreEqual(true, result);
			Assert::IsTrue(op[0]);
			Assert::IsFalse(op[1]);

		}

		TEST_METHOD(NextVariation_On2bit01)
		{
			std::vector<bool> op = { false, true };
			auto result = ov.NextVariation(op);

			Assert::AreEqual(true, result);
			Assert::IsTrue(op[0]);
			Assert::IsTrue(op[1]);
		}

		TEST_METHOD(NextVariation_On2bit10)
		{
			std::vector<bool> op = { true, false };
			auto result = ov.NextVariation(op);

			Assert::AreEqual(true, result);
			Assert::IsFalse(op[0]);
			Assert::IsTrue(op[1]);
		}

		TEST_METHOD(NextVariation_On2bit11)
		{
			std::vector<bool> op = { true, true };
			auto result = ov.NextVariation(op);

			Assert::AreEqual(false, result);
		}

	private:
		OperationVariator ov;
	};

}