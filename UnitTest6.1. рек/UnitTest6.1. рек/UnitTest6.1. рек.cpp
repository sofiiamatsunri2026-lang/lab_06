#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_06_1. рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61рек
{
	TEST_CLASS(UnitTest61рек)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int n = 10;
			int r[n] = { 4, 7, 13, 26, 15, 39, 21, 8, 65, 9 };

			int t = Count(r, n, 0);

			Assert::AreEqual(4, t);
		}

		// Sum: 7 + 15 + 21 + 9 = 52
		TEST_METHOD(TestSum)
		{
			const int n = 10;
			int r[n] = { 4, 7, 13, 26, 15, 39, 21, 8, 65, 9 };

			int t = Sum(r, n, 0);

			Assert::AreEqual(52, t);
		}

		// Zero: підходящі елементи замінюються нулями, решта не змінюється
		TEST_METHOD(TestZero)
		{
			const int n = 10;
			int r[n] = { 4, 7, 13, 26, 15, 39, 21, 8, 65, 9 };
			int expected[n] = { 4, 0, 13, 26, 0, 39, 0, 8, 65, 0 };

			Zero(r, n, 0);

			for (int i = 0; i < n; i++)
				Assert::AreEqual(expected[i], r[i]);
		}
	};

}