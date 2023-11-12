#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#include "triangleSolver.h"

#define PI 3.141592653

bool isTriangle(int side1, int side2, int side3) {
	// Check if any of the sides is less than 0
	if (side1 < 0 || side2 < 0 || side3 < 0) {
		return false;
	}

	// Check if any of the sides is equal to the sum of the other two sides
	if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
		return false;
	}

	// If all the above checks pass, then the three sides form a triangle
	return true;
}

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

float* getTriangleAngles(int side1, int side2, int side3) {

	float* angles = (float*) malloc (sizeof(float) * 3);
	if (angles == NULL) {
		fprintf(stderr, "MALLOC ERROR: Error allocating memory");
		return NULL;
	}

	//Calculate the cosine of angles using the law of cosines
	float cosA = (float)(side2 * side2 + side3 * side3 - side1 * side1) / (2 * (float)side2 * (float)side3);
	float cosB = (float)(side1 * side1 + side3 * side3 - side2 * side2) / (2 * (float)side1 * (float)side3);
	float cosC = (float)(side1 * side1 + side2 * side2 - side3 * side3) / (2 * (float)side1 * (float)side2);

	//Convert the cosines to angles in degrees using acosf()
	//The angles are then converted from radians to degrees
	angles[0] = (float) ( acosf(cosA) * (180.0f / PI) );
	angles[1] = (float) ( acosf(cosB) * (180.0f / PI) );
	angles[2] = (float) ( acosf(cosC) * (180.0f / PI) );

	return angles;
}