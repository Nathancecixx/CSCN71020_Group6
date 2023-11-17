#include "pch.h"
#include "CppUnitTest.h"
#include<stdbool.h>

extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" float* getTriangleAngles(int side1, int side2, int side3);
extern "C" bool isTriangle(int side1, int side2, int side3);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TDD
{
	TEST_CLASS(TDD)
	{
	public:

		TEST_METHOD(Check_Equilateral)
		{
			// Check if Function return Equilateral a=3 b=3 c=3

			char* result = analyzeTriangle(3, 3, 3);

			Assert::AreEqual("Equilateral triangle", result);

		}
		TEST_METHOD(Check_Scalne) {

			// Check if Function return Scalene a=3 b=4 c=5

			char* result = analyzeTriangle(3, 4, 5);

			Assert::AreEqual("Scalene triangle", result);
		}

		TEST_METHOD(Check_Isosceles) {

			// Check if Function return Isosceles a=3 b=3 c=4

			char* result = analyzeTriangle(3, 3, 4);

			Assert::AreEqual("Isosceles triangle", result);
		}

		TEST_METHOD(Check_NotTriangle) {

			// Check if Function return Not a triangle a=0 b=3 c=4

			char* result = analyzeTriangle(0, 3, 4);

			Assert::AreEqual("Not a triangle", result);
		}
		TEST_METHOD(Check_Angle) {

			// Check if Function return Angle a=3 b=4 c=5

			float* result = getTriangleAngles(3, 4, 5);

			Assert::AreEqual(36.8699f, result[0]);
			Assert::AreEqual(53.1301f, result[1]);
			Assert::AreEqual(90.0f, result[2]);
		}

		TEST_METHOD(Check_Angle2) {

			// Check if Function return Angle a=3 b=3 c=3

			float* result = getTriangleAngles(3, 3, 3);

			Assert::AreEqual(60.0f, result[0]);
			Assert::AreEqual(60.0f, result[1]);
			Assert::AreEqual(60.0f, result[2]);
		}

		TEST_METHOD(Check_Angle3) {

			// Check if Function return Angle a=3 b=3 c=4

			float* result = getTriangleAngles(3, 3, 4);

			Assert::AreEqual(36.8699f, result[0]);
			Assert::AreEqual(36.8699f, result[1]);
			Assert::AreEqual(106.2602f, result[2]);
		}
		TEST_METHOD(Check_Triangle) {

			// Check if Function return Triangle a=3 b=3 c=3

			bool result = isTriangle(3, 3, 3);

			Assert::IsTrue(result);
		}
		TEST_METHOD(Check_Triangle2) {

			// Check if Function return Triangle a=3 b=3 c=4

			bool result = isTriangle(3, 3, 4);

			Assert::IsTrue(result);
		}
		TEST_METHOD(Not_Triangle) {

			// Check if Function return Not Triangle a=0 b=3 c=4

			bool result = isTriangle(0, 3, 4);

			Assert::IsFalse(result);

		}
	};

}

namespace Rectangle
{
	TEST_CLASS(Rectangle) {

		TEST_METHOD(Is_Rectangle) {


		}
	};
}
