#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_06_1.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61
{
	TEST_CLASS(UnitTest61)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 10;
			int r[n] = { 4, 7, 13, 26, 15, 39, 21, 8, 65, 9 };

			int t = Count(r, n);

			Assert::AreEqual(4, t);
		}

	
		TEST_METHOD(TestSum)
		{
			const int n = 10;
			int r[n] = { 4, 7, 13, 26, 15, 39, 21, 8, 65, 9 };

			int t = Sum(r, n);

			Assert::AreEqual(52, t);
		}

		
		TEST_METHOD(TestZero)
		{
			const int n = 10;
			int r[n] = { 4, 7, 13, 26, 15, 39, 21, 8, 65, 9 };
			int expected[n] = { 4, 0, 13, 26, 0, 39, 0, 8, 65, 0 };

			Zero(r, n);

			for (int i = 0; i < n; i++)
				Assert::AreEqual(expected[i], r[i]);
		}

		TEST_METHOD(TestNoSuitableElements)
		{
			const int n = 4;
			int r[n] = { 2, 13, 26, 4 };

			Assert::AreEqual(0, Count(r, n));
			Assert::AreEqual(0, Sum(r, n));
		}
	};
}
