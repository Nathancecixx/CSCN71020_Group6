#include "pch.h"
#include "CppUnitTest.h"
#include<stdbool.h>
// Test cases for triangle.c 

extern "C" float calculateAngleA(float, float, float);
extern "C" bool isTriangle(float, float, float);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Triangle_Check)
		{
			// Check if is triangle works 
			float a = 3;
			float b = 3;
			float c = 3;
			float expected = 0;
			float d = 0.5;
			expected = calculateAngleA(a, b, c);
			Assert::AreEqual(d, expected);


		}
	};
}
