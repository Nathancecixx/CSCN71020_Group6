#include <stdio.h>
#include <math.h>
#include "triangle.h"
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS

bool isTriangle(float side1, float side2, float side3) {
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

void calculateAngles(float side1, float side2, float side3, float* angleA, float* angleB, float* angleC) {
    // Calculate the semi-perimeter of the triangle
    float s = (side1 + side2 + side3) / 2;

    // Calculate the three interior angles using the Law of Cosines
    *angleA = acosf((float)(side2 * side2 + side3 * side3 - side1 * side1) / (2 * (float)side2 * (float)side3));
    *angleB = acosf((float)(side1 * side1 + side3 * side3 - side2 * side2) / (2 * (float)side1 * (float)side3));
    *angleC = acosf((float)(side1 * side1 + side2 * side2 - side3 * side3) / (2 * (float)side1 * (float)side2));
}

int main(void) {
    float side1 = 5;
    float side2 = 6;
    float side3 = 7;

    // Check if the triangle is valid
    if (!isTriangle(side1, side2, side3)) {
        printf("The triangle is not valid.\n");
        return 1;
    }

    // Calculate the angles of the triangle
    float angleA;
    float angleB;
    float angleC;
    calculateAngles(side1, side2, side3, &angleA, &angleB, &angleC);

    // Print the angles of the triangle
    printf("Angle A: %f degrees\n", angleA);
    printf("Angle B: %f degrees\n", angleB);
    printf("Angle C: %f degrees\n", angleC);

    return 0;
}
