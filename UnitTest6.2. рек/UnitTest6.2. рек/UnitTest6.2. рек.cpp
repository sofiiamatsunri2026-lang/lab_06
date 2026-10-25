#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_06_2. рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62рек
{
	TEST_CLASS(UnitTest62рек)
	{
	public:
		
		// звичайний випадок: найбільший непарний елемент - у середині масиву
		TEST_METHOD(MaxOdd_Middle)
		{
			const int n = 5;
			int r[n] = { 4, 13, 10, 7, 22 };
			int max = 0;

			bool found = MaxOdd(r, n, 0, max);

			Assert::IsTrue(found);
			Assert::AreEqual(13, max);
		}

		// найбільший елемент масиву - парний, його ігноруємо
		TEST_METHOD(MaxOdd_IgnoreEven)
		{
			const int n = 5;
			int r[n] = { 5, 68, 9, 66, 7 };
			int max = 0;

			bool found = MaxOdd(r, n, 0, max);

			Assert::IsTrue(found);
			Assert::AreEqual(9, max);
		}

		// непарний елемент лише один і він останній
		TEST_METHOD(MaxOdd_OnlyOneOdd)
		{
			const int n = 4;
			int r[n] = { 4, 6, 8, 11 };
			int max = 0;

			bool found = MaxOdd(r, n, 0, max);

			Assert::IsTrue(found);
			Assert::AreEqual(11, max);
		}

		// непарних елементів немає
		TEST_METHOD(MaxOdd_NoOdd)
		{
			const int n = 4;
			int r[n] = { 4, 6, 8, 68 };
			int max = 0;

			bool found = MaxOdd(r, n, 0, max);

			Assert::IsFalse(found);
		}
	};
}
