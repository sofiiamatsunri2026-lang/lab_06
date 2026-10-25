#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_06_4. рек.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64рек
{
	TEST_CLASS(UnitTest64рек)
	{
	public:
		
		// добуток від'ємних елементів
		TEST_METHOD(ProductNegative_Test)
		{
			const int n = 4;
			double a[n] = { 2, -3, 5, -4 };

			Assert::AreEqual(12.0, ProductNegative(a, n, 0), 1e-8);
		}

		// сума додатних елементів до максимального
		TEST_METHOD(SumPositiveBefore_Test)
		{
			const int n = 5;
			double a[n] = { 1, -2, 3, 10, 4 };

			int imax = MaxIndex(a, n, 0, 0);

			Assert::AreEqual(3, imax);
			Assert::AreEqual(4.0, SumPositiveBefore(a, imax, 0), 1e-8);
		}

		// зворотний порядок парних елементів
		TEST_METHOD(ReverseEven_Test)
		{
			const int n = 5;
			double a[n] = { 2, 1, 4, 3, 6 };
			double expected[n] = { 6, 1, 4, 3, 2 };

			ReverseEven(a, 0, n - 1);

			for (int i = 0; i < n; i++)
				Assert::AreEqual(expected[i], a[i], 1e-8);
		}
	};
}
