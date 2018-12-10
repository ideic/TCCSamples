#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\TCCTasks\Task1TransformationFinder.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace Task1;

namespace TestTCCTest
{		
	TEST_CLASS(TaskTest1)
	{
	public:
		TEST_METHOD(canObtain_B_ABBA_Possible)
		{
			auto result = t1.canObtain(string("B"), string("ABBA"));

			Assert::AreEqual(string("Possible"), result);
		};

		TEST_METHOD(canObtain_AB_ABB_Impossible)
		{
			auto result = t1.canObtain(string("AB"), string("ABB"));

			Assert::AreEqual(string("Impossible"), result);
		};

		TEST_METHOD(canObtain_BBAB_ABABABABB_Impossible)
		{
			auto result = t1.canObtain(string("BBAB"), string("ABABABABB"));

			Assert::AreEqual(std::string("Impossible"), result);
		};

		TEST_METHOD(canObtain_BBBBABABBBBBBA_BBBBABABBABBBBBBABABBBBBBBBABAABBBAA_Possible)
		{
			auto result = t1.canObtain(string("BBBBABABBBBBBA"), string("BBBBABABBABBBBBBABABBBBBBBBABAABBBAA"));

			Assert::AreEqual(std::string("Possible"), result);
		};

		TEST_METHOD(canObtain_A_BB_Impossible)
		{
			auto result = t1.canObtain(string("A"), string("BB"));

			Assert::AreEqual(std::string("Impossible"), result);
		};

		TEST_METHOD(canObtain_A_AA_Possible)
		{
			auto result = t1.canObtain(string("A"), string("AA"));

			Assert::AreEqual(std::string("Possible"), result);
		};

	private:
		Task1TransformationFinder t1;
	};

}