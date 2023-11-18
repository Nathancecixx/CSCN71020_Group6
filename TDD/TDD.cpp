#include"pch.h"
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

		TEST_METHOD(Check_Equilateral2) {

			// Check if Function return Equilateral a=4 b=4 c=4

			char* result = analyzeTriangle(4, 4, 4);

			Assert::AreEqual("Equilateral triangle", result);
		}

		TEST_METHOD(Check_Equilateral3) {

			// Check if Function return Equilateral a=5 b=5 c=5

			char* result = analyzeTriangle(25, 25, 25);

			Assert::AreEqual("Equilateral triangle", result);
		}


		TEST_METHOD(Check_Scalne) {

			// Check if Function return Scalene a=3 b=4 c=5

			char* result = analyzeTriangle(3, 4, 5);

			Assert::AreEqual("Scalene triangle", result);
		}

		TEST_METHOD(Check_Scalne2) {

			// Check if Function return Scalene a=4 b=5 c=6

			char* result = analyzeTriangle(4, 5, 6);

			Assert::AreEqual("Scalene triangle", result);
		}

		TEST_METHOD(Check_Scalne3) {

			// Check if Function return Scalene a=5 b=6 c=7

			char* result = analyzeTriangle(10, 11, 12);

			Assert::AreEqual("Scalene triangle", result);
		}

		TEST_METHOD(Check_Isosceles) {

			// Check if Function return Isosceles a=3 b=3 c=4

			char* result = analyzeTriangle(3, 3, 4);

			Assert::AreEqual("Isosceles triangle", result);
		}

		TEST_METHOD(Check_Isosceles2) {

			// Check if Function return Isosceles a=4 b=4 c=5

			char* result = analyzeTriangle(4, 4, 5);

			Assert::AreEqual("Isosceles triangle", result);
		}

		TEST_METHOD(Check_Isosceles3) {

			// Check if Function return Isosceles a=5 b=5 c=6

			char* result = analyzeTriangle(10, 10, 9);

			Assert::AreEqual("Isosceles triangle", result);
		}

		TEST_METHOD(Check_NotTriangle) {

			// Check if Function return Not a triangle a=0 b=3 c=4

			char* result = analyzeTriangle(0, 3, 4);

			Assert::AreEqual("Not a triangle", result);
		}

		TEST_METHOD(Check_NotTriangle2) {

			// Check if Function return Not a triangle a=1 b=0 c=4

			char* result = analyzeTriangle(1, 0, 4);

			Assert::AreEqual("Not a triangle", result);
		}

		TEST_METHOD(Check_NotTriangle3) {

			// Check if Function return Not a triangle a=2 b=20 c=0

			char* result = analyzeTriangle(2, 20, 0);

			Assert::AreEqual("Not a triangle", result);
		}

		TEST_METHOD(Check_Angle) {

			// Check if Function return Angle a=3 b=4 c=5

			float* result = getTriangleAngles(3, 4, 5);

			Assert::AreEqual(36.869896f, result[0]);
			Assert::AreEqual(53.130100f, result[1]);
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

			Assert::AreEqual(48.189682f, result[0]);
			Assert::AreEqual(48.189682f, result[1]);
			Assert::AreEqual(83.620636f, result[2]);
		}

		TEST_METHOD(Check_Angle4) {

			// Check if Function return Angle a=4 b=4 c=5

			float* result = getTriangleAngles(4, 4, 5);

			Assert::AreEqual(51.317814f, result[0]);
			Assert::AreEqual(51.317814f, result[1]);
			Assert::AreEqual(77.364380f, result[2]);
		}

		TEST_METHOD(Check_Angle5) {

			// Check if Function return Angle a=10 b=11 c=13

			float* result = getTriangleAngles(10, 11, 13);

			Assert::AreEqual(48.368618f, result[0]);
			Assert::AreEqual(55.303398f, result[1]);
			Assert::AreEqual(76.327980f, result[2]);
		}

		TEST_METHOD(Check_Angle6) {

			// Check if Function return Angle a=5 b=6 c=7

			float* result = getTriangleAngles(5, 6, 7);

			Assert::AreEqual(44.415306f, result[0]);
			Assert::AreEqual(57.121647f, result[1]);
			Assert::AreEqual(78.463043f, result[2]);
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

		TEST_METHOD(Check_Triangle3) {

			// Check if Function return Triangle a=4 b=4 c=5

			bool result = isTriangle(4, 4, 5);

			Assert::IsTrue(result);
		}

		TEST_METHOD(Check_Triangle4) {

			// Check if Function return Triangle a=4 b=5 c=6

			bool result = isTriangle(4, 5, 6);

			Assert::IsTrue(result);
		}

		TEST_METHOD(Not_Triangle) {

			// Check if Function return Not Triangle a=0 b=3 c=4

			bool result = isTriangle(0, 3, 4);

			Assert::IsFalse(result);

		}

		TEST_METHOD(Not_Triangle2) {

			// Check if Function return Not Triangle a=1 b=3 c=4

			bool result = isTriangle(1, 3, 4);

			Assert::IsFalse(result);

		}

		TEST_METHOD(Not_Triangle3) {

			// Check if Function return Not Triangle a=2 b=6 c=4

			bool result = isTriangle(2, 6, 4);

			Assert::IsFalse(result);

		}

		TEST_METHOD(Not_Triangle4) {

			// Check if Function return Not Triangle a=3 b=4 c=7

			bool result = isTriangle(3, 4, 7);

			Assert::IsFalse(result);

		}
	};
}