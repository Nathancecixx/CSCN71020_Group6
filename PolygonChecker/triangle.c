#include <stdio.h>
#include <math.h>
#include "triangle.h"
#include <stdbool.h>
#define CRT_SECURE_NO_WARNINGS

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

bool isTriangleValid(float side1, float side2, float side3) {
    return isTriangle(side1, side2, side3);
}

float calculateAngleA(float side1, float side2, float side3) {
    float angleA;
    calculateAngles(side1, side2, side3, &angleA, NULL, NULL);
    return angleA;
}

float calculateAngleB(float side1, float side2, float side3) {
    float angleB;
    calculateAngles(side1, side2, side3, NULL, &angleB, NULL);
    return angleB;
}

float calculateAngleC(float side1, float side2, float side3) {
    float angleC;
    calculateAngles(side1, side2, side3, NULL, NULL, &angleC);
    return angleC;
}
