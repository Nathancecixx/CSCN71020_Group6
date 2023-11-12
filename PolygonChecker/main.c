#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>

#include "main.h"

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			//Take triangle sides as input
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);

			//If triangle sides arnt a triangle then give a error message and break
			if (!isTriangle(triangleSides[0], triangleSides[1], triangleSides[2])) {
				fprintf(stderr, "ERROR: Sides do not make a triangle.");
				break;
			}

			//Print the type of triangle
			char* triangleType = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", triangleType);

			//Get the angles associated with the 3 sides
			float* angles = getTriangleAngles(triangleSides[0], triangleSides[1], triangleSides[2]);
			if (angles == NULL) {
				break;
			}

			//Print the angles and free memory
			for (int i = 0; i < 3; i++) {
				printf("Angle %d: %f\n", i + 1, angles[i]);
			}
			free(angles);

			break;

		case 2:
			printf_s("Rectangle selected.\n");

			//Create 2d array to store points of rectangle
			POINT ArrOfPoints[4];

			//Iterate 4 times to take 4 inputs
			for (int i = 0; i < 4; i++) {
				//Take input from user and store it in tmp int array of size 2
				POINT* TmpPointPntr = getRectangleSides();
				//fill in i point of 2d array with inputted x and y values
				ArrOfPoints[i].x = TmpPointPntr->x;
				ArrOfPoints[i].y = TmpPointPntr->y;
				//Free memory used to temp variable
				free(TmpPointPntr);
			}

			//Sort points into proper order (Top Right) (Bottom Right) (Bottom Left) (Top Left)
			SortPoints(ArrOfPoints);

			//Test if points form a rectangle.
			if (is_Recatngle(ArrOfPoints)) {
				printf("This is a rectangle with: \n");
				printf("Perameter of: %d\n", get_Peram(ArrOfPoints));
				printf("Area of: %d\n", get_Area(ArrOfPoints));
			}
			else {
				printf("This is not a rectangle");
			}
			break;


		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");

			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%d", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

POINT* getRectangleSides() {

	POINT* rectPoint = (POINT*)malloc(sizeof(POINT));
	printf("Please enter point, x and y:\n");
	scanf_s("%d", &rectPoint->x);
	scanf_s("%d", &rectPoint->y);
	return rectPoint;
}