#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_06_3. рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63рек
{
	TEST_CLASS(UnitTest63рек)
	{
	public:
		
		// звичайна функція
		TEST_METHOD(CountPositive_Int)
		{
			const int n = 5;
			int a[n] = { 1, -2, 0, 3, -4 };

			Assert::AreEqual(2, CountPositive(a, n, 0));
		}

		// шаблон, тип double
		TEST_METHOD(CountPositive_Double)
		{
			const int n = 5;
			double b[n] = { 1.5, -2.5, 0.0, 3.5, 4.5 };

			Assert::AreEqual(3, CountPositive<double>(b, n, 0));
		}
	};
}
