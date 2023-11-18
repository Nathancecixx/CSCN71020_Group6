#include <stdbool.h>
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef struct point {
	int x;
	int y;
}POINT;

extern "C" void SortPoints(POINT* arrOfPoints);
extern "C" bool is_Recatngle(POINT* arrOfPoints);
extern "C" int get_Peram(POINT* arrOfPoints);
extern "C" int get_Area(POINT* arrOfPoints);
extern "C" int get_Distance(POINT pointA, POINT pointB);
extern "C" bool is_Orthoginal(POINT pointA, POINT pointB, POINT pointC);


namespace UnitTestsRectangle
{

	
	/********************************************
     * This section tests SortPoints() function *
     ********************************************/
	TEST_CLASS(SortPoints_Tests)
	{
	public:

		/// <summary>
		/// Test Valid Rectangle Points
		/// </summary>
		TEST_METHOD(Functional_Test_1)
		{
			//Create hard-coded points
			POINT point1 = { 4, 2 };
			POINT point2 = { 4, -2 };
			POINT point3 = { -4, -2 };
			POINT point4 = { -4, 2 };

			POINT arrOfPoints[4] = { point1, point2, point3, point4 };

			SortPoints(arrOfPoints);

			//Create expected array that is in the proper order.
			POINT expectedArr[4] = { point1, point2, point3, point4 };
			
			//iterate through and check if current expected points 
			//X and Y is equal too the sorted arrays's
			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(expectedArr[i].x, arrOfPoints[i].x);
				Assert::AreEqual(expectedArr[i].y, arrOfPoints[i].y);
			}
		}

		TEST_METHOD(Functional_Test_2)
		{
			//Create hard-coded points
			POINT point1 = { 4, 2 };
			POINT point2 = { 4, -2 };
			POINT point3 = { -4, -2 };
			POINT point4 = { -4, 2 };

			POINT arrOfPoints[4] = { point2, point3, point4, point1 };
			
			SortPoints(arrOfPoints);

			//Create expected array that is in the proper order.
			POINT expectedArr[4] = { point1, point2, point3, point4 };

			//iterate through and check if current expected points 
			//X and Y is equal too the sorted arrays's
			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(expectedArr[i].x, arrOfPoints[i].x);
				Assert::AreEqual(expectedArr[i].y, arrOfPoints[i].y);
			}
		}

		TEST_METHOD(Functional_Test_3)
		{
			//Create hard-coded points
			POINT point1 = { 4, 2 };
			POINT point2 = { 4, -2 };
			POINT point3 = { -4, -2 };
			POINT point4 = { -4, 2 };

			POINT arrOfPoints[4] = { point3, point4, point1, point2 };

			SortPoints(arrOfPoints);

			//Create expected array that is in the proper order.
			POINT expectedArr[4] = { point1, point2, point3, point4 };

			//iterate through and check if current expected points 
			//X and Y is equal too the sorted arrays's
			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(expectedArr[i].x, arrOfPoints[i].x);
				Assert::AreEqual(expectedArr[i].y, arrOfPoints[i].y);
			}
		}

		TEST_METHOD(Functional_Test_4)
		{
			//Create hard-coded points
			POINT point1 = { 4, 2 };
			POINT point2 = { 4, -2 };
			POINT point3 = { -4, -2 };
			POINT point4 = { -4, 2 };

			POINT arrOfPoints[4] = { point4, point3, point2, point1 };
			
			SortPoints(arrOfPoints);

			//Create expected array that is in the proper order.
			POINT expectedArr[4] = { point1, point2, point3, point4 };

			//iterate through and check if current expected points 
			//X and Y is equal too the sorted arrays's
			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(expectedArr[i].x, arrOfPoints[i].x);
				Assert::AreEqual(expectedArr[i].y, arrOfPoints[i].y);
			}
		}

		TEST_METHOD(Functional_Test_5)
		{
			//Create hard-coded points
			POINT point1 = { 4, 2 };
			POINT point2 = { 4, -2 };
			POINT point3 = { -4, -2 };
			POINT point4 = { -4, 2 };

			POINT arrOfPoints[4] = { point2, point4, point1, point3 };

			SortPoints(arrOfPoints);

			//Create expected array that is in the proper order.
			POINT expectedArr[4] = { point1, point2, point3, point4 };

			//iterate through and check if current expected points 
			//X and Y is equal too the sorted arrays's
			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(expectedArr[i].x, arrOfPoints[i].x);
				Assert::AreEqual(expectedArr[i].y, arrOfPoints[i].y);
			}
		}

		TEST_METHOD(Functional_Test_6)
		{
			//Create hard-coded points
			POINT point1 = { 3, 3 };
			POINT point2 = { 3, -1 };
			POINT point3 = { -3, -1 };
			POINT point4 = { -3, 2 };

			POINT arrOfPoints[4] = { point4, point1, point3, point2 };
			
			SortPoints(arrOfPoints);

			//Create expected array that is in the proper order.
			POINT expectedArr[4] = { point1, point2, point3, point4 };

			//iterate through and check if current expected points 
			//X and Y is equal too the sorted arrays's
			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(expectedArr[i].x, arrOfPoints[i].x);
				Assert::AreEqual(expectedArr[i].y, arrOfPoints[i].y);
			}
		}

		TEST_METHOD(Functional_Test_7)
		{
			//Create hard-coded points
			POINT point1 = { 3, 3 };
			POINT point2 = { 3, -1 };
			POINT point3 = { -3, -1 };
			POINT point4 = { -3, 2 };

			POINT arrOfPoints[4] = { point2, point4, point3, point1 };

			SortPoints(arrOfPoints);

			//Create expected array that is in the proper order.
			POINT expectedArr[4] = { point1, point2, point3, point4 };

			//iterate through and check if current expected points 
			//X and Y is equal too the sorted arrays's
			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(expectedArr[i].x, arrOfPoints[i].x);
				Assert::AreEqual(expectedArr[i].y, arrOfPoints[i].y);
			}
		}

		TEST_METHOD(Functional_Test_8)
		{
			//Create hard-coded points
			POINT point1 = { 3, 3 };
			POINT point2 = { 3, -1 };
			POINT point3 = { -3, -1 };
			POINT point4 = { -3, 2 };

			POINT arrOfPoints[4] = { point3, point1, point2, point4 };
			
			SortPoints(arrOfPoints);

			//Create expected array that is in the proper order.
			POINT expectedArr[4] = { point1, point2, point3, point4 };

			//iterate through and check if current expected points 
			//X and Y is equal too the sorted arrays's
			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(expectedArr[i].x, arrOfPoints[i].x);
				Assert::AreEqual(expectedArr[i].y, arrOfPoints[i].y);
			}
		}
	};


	/**********************************************
	 * This section tests Is_Rectangle() function *
	 **********************************************/
	TEST_CLASS(Is_Rectangle_Tests)
	{
	public:
		
		/// <summary>
		/// Test Valid Rectangle Points
		/// </summary>
		TEST_METHOD(Functional_Test_1)
		{
			//Create hard-coded points
			POINT point1 = { 4, 2 };
			POINT point2 = { 4, -2 };
			POINT point3 = { -4, -2 };
			POINT point4 = { -4, 2 };

			POINT arrOfPoints[4] = { point1, point2, point3, point4 };

			bool result = is_Recatngle(arrOfPoints);

			Assert::AreEqual (true, result);
		}

		TEST_METHOD(Functional_Test_2)
		{
			//Create hard-coded points
			POINT point1 = { 3, 2 };
			POINT point2 = { 3, -2 };
			POINT point3 = { -3, -2 };
			POINT point4 = { -3, 2 };

			POINT arrOfPoints[4] = { point1, point2, point3, point4 };
			bool result = is_Recatngle(arrOfPoints);
			Assert::AreEqual(true, result);
		}

		/// <summary>
		/// Test Non Valid Rectangle Points
		/// </summary>
		TEST_METHOD(Exception_Test_1)
		{
			//Create hard-coded points
			POINT point1 = { 3, 3 };
			POINT point2 = { 3, -1 };
			POINT point3 = { -3, -1 };
			POINT point4 = { -3, 2 };

			POINT arrOfPoints[4] = { point1, point2, point3, point4 };
			bool result = is_Recatngle(arrOfPoints);
			Assert::AreEqual(false, result);
		}
		TEST_METHOD(Exception_Test_2)
		{
			//Create hard-coded points
			POINT point1 = { 2, 4 };
			POINT point2 = { 5, -3 };
			POINT point3 = { -2, -4 };
			POINT point4 = { -2, 3 };

			POINT arrOfPoints[4] = { point1, point2, point3, point4 };
			bool result = is_Recatngle(arrOfPoints);
			Assert::AreEqual(false, result);
		}
	};


	/*******************************************
     * This section tests Get_Peram() function *
     *******************************************/
	TEST_CLASS(Get_Peram_Tests)
	{
	public:

		/// <summary>
		/// Test Valid Rectangle Points
		/// </summary>
		TEST_METHOD(Functional_Test_1) 
		{
			//Create hard-coded points
			POINT point1 = { 4, 2 };
			POINT point2 = { 4, -2 };
			POINT point3 = { -4, -2 };
			POINT point4 = { -4, 2 };

			POINT arrOfPoints[4] = { point1, point2, point3, point4 };
			int result = get_Peram(arrOfPoints);
			Assert::AreEqual(24, result);
		}

		TEST_METHOD(Functional_Test_2)
		{
			//Create hard-coded points
			POINT point1 = { 3, 2 };
			POINT point2 = { 3, -2 };
			POINT point3 = { -3, -2 };
			POINT point4 = { -3, 2 };

			POINT arrOfPoints[4] = { point1, point2, point3, point4 };
			int result = get_Peram(arrOfPoints);
			Assert::AreEqual(20, result);
		}

		TEST_METHOD(Functional_Test_3)
		{
			//Create hard-coded points
			POINT point1 = { 3, 3 };
			POINT point2 = { 3, -1 };
			POINT point3 = { -3, -1 };
			POINT point4 = { -3, 3 };

			POINT arrOfPoints[4] = { point1, point2, point3, point4 };
			int result = get_Peram(arrOfPoints);

			Assert::AreEqual(20, result);
		}

		TEST_METHOD(Function_Test_4)
		{
			//Create hard-coded points
			POINT point1 = { 2, 4 };
			POINT point2 = { 2, -3 };
			POINT point3 = { -2, -3 };
			POINT point4 = { -2, 4 };

			POINT arrOfPoints[4] = { point1, point2, point3, point4 };
			int result = get_Peram(arrOfPoints);
			Assert::AreEqual(22, result);
		}



	};


	/******************************************
     * This section tests Get_Area() function *
     ******************************************/
	TEST_CLASS(Get_Area_Tests)
	{
	public:

		/// <summary>
		/// Test Valid Rectangle Points
		/// </summary>
		TEST_METHOD(Functional_Test_1)
		{
			//Create hard-coded points
			POINT point1 = { 4, 2 };
			POINT point2 = { 4, -2 };
			POINT point3 = { -4, -2 };
			POINT point4 = { -4, 2 };

			POINT arrOfPoints[4] = { point1, point2, point3, point4 };

			int result = get_Area(arrOfPoints);
			Assert::AreEqual(32, result);
		}

		TEST_METHOD(Functional_Test_2)
		{
			//Create hard-coded points
			POINT point1 = { 3, 2 };
			POINT point2 = { 3, -2 };
			POINT point3 = { -3, -2 };
			POINT point4 = { -3, 2 };

			POINT arrOfPoints[4] = { point1, point2, point3, point4 };

			int result = get_Area(arrOfPoints);
			Assert::AreEqual(24, result);
		}

		TEST_METHOD(Functional_Test_3)
		{
			//Create hard-coded points
			POINT point1 = { 2, 4 };
			POINT point2 = { 2, -4 };
			POINT point3 = { -2, -4 };
			POINT point4 = { -2, 4 };

			POINT arrOfPoints[4] = { point1, point2, point3, point4 };

			int result = get_Area(arrOfPoints);
			Assert::AreEqual(32, result);
		}

		TEST_METHOD(Functional_Test_4)
		{
			//Create hard-coded points
			POINT point1 = { 5, 4 };
			POINT point2 = { 5, -4 };
			POINT point3 = { -5, -4 };
			POINT point4 = { -5, 4 };

			POINT arrOfPoints[4] = { point1, point2, point3, point4 };

			int result = get_Area(arrOfPoints);
			Assert::AreEqual(80, result);
		}
	};

		/**********************************************
         * This section tests Get_Distance() function *
         **********************************************/
		TEST_CLASS(Get_Distance_Tests)
		{
		public:

			/// <summary>
			/// Test Valid Rectangle Points
			/// </summary>
			TEST_METHOD(Functional_Test_1)
			{
				//Create hard-coded points
				POINT point1 = { 4, 2 };
				POINT point2 = { 4, -2 };

				//Get the distance between 2 points
				//and check if it is whats expected
				int result = get_Distance(point1, point2);
				Assert::AreEqual(4, result);
			}

			TEST_METHOD(Functional_Test_2)
			{
				//Create hard-coded points
				POINT point1 = { -2, -3 };
				POINT point2 = { 2, -3 };

				//Get the distance between 2 points
				//and check if it is whats expected
				int result = get_Distance(point1, point2);
				Assert::AreEqual(4, result);
			}

			TEST_METHOD(Functional_Test_3)
			{
				//Create hard-coded points
				POINT point1 = { 3, 3 };
				POINT point2 = { 3, -1 };

				//Get the distance between 2 points
				//and check if it is whats expected
				int result = get_Distance(point1, point2);
				Assert::AreEqual(4, result);
			}

			TEST_METHOD(Functional_Test_4)
			{
				//Create hard-coded points
				POINT point1 = { -6, 8 };
				POINT point2 = {-6, -9 };

				//Get the distance between 2 points
                //and check if it is whats expected
				int result = get_Distance(point1, point2);
				Assert::AreEqual(17, result);
			}
		
	};



		/************************************************
	     * This section tests Is_Orthogoinal() function *
	     ************************************************/
		TEST_CLASS(is_Orthoginal_Tests)
		{
		public:

			/// <summary>
			/// Test Orthoginal Points
			/// </summary>
			TEST_METHOD(Functional_Test_1)
			{
				//Create hard-coded points
				POINT point1 = { 4, 2 };
				POINT point2 = { 4, -2 };
				POINT point3 = { -4, -2 };

				bool result = is_Orthoginal(point1, point2, point3);
				Assert::AreEqual(true, result);
			}

			TEST_METHOD(Functional_Test_2)
			{
				//Create hard-coded points
				POINT point1 = { 3, 2 };
				POINT point2 = { 3, -2 };
				POINT point3 = { -3, -2 };

				bool result = is_Orthoginal(point1, point2, point3);
				Assert::AreEqual(true, result);
			}

			/// <summary>
			/// Test Non-Orthoginal Points
			/// </summary>
			TEST_METHOD(Exception_Test_1)
			{
				//Create hard-coded points
				POINT point1 = { -3, 2 };
				POINT point2 = { 3, 3 };
				POINT point3 = { 3, -1 };

				bool result = is_Orthoginal(point1, point2, point3);
				Assert::AreEqual(false, result);
			}
			TEST_METHOD(Exception_Test_2)
			{
				//Create hard-coded points
				POINT point1 = { 2, 4 };
				POINT point2 = { 5, -3 };
				POINT point3 = { -2, -4 };

				bool result = is_Orthoginal(point1, point2, point3);
				Assert::AreEqual(false, result);
			}
		};
}
