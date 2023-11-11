#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include"main.h"
#include"triangle.h"
#include"triangleSolver.h"

bool isTriangle(float side1, float side2, float side3) {
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        return false;
    }

    if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        return false;
    }

    return true;
}

void calculateAngles(float side1, float side2, float side3, float* angleA, float* angleB, float* angleC) {
    float s = (side1 + side2 + side3) / 2;

    *angleA = acosf((side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3));
    *angleB = acosf((side1 * side1 + side3 * side3 - side2 * side2) / (2 * side1 * side3));
    *angleC = acosf((side1 * side1 + side2 * side2 - side3 * side3) / (2 * side1 * side2));
}

char* analyzeTriangle(float side1, float side2, float side3) {
    if (!isTriangle(side1, side2, side3)) {
        return "The triangle is not valid.";
    }

    float angleA, angleB, angleC;
    calculateAngles(side1, side2, side3, &angleA, &angleB, &angleC);

    char* result = malloc(256);
    sprintf(result, "The triangle is valid. The angles are:\n* Angle A: %.2f degrees\n* Angle B: %.2f degrees\n* Angle C: %.2f degrees", angleA, angleB, angleC);
    return result;
}

void printWelcome() {
    printf("\n");
    printf(" **********************\n");
    printf("**   Welcome to   **\n");
    printf("**  Polygon Checker **\n");
    printf(" **********************\n");
}

int printShapeMenu() {
    printf("1. Triangle\n");
    printf("0. Exit\n");

    int shapeChoice;
    printf("Enter number: ");
    scanf("%d", &shapeChoice);

    return shapeChoice;
}

int main() {
    bool continueProgram = true;
    while (continueProgram) {
        printWelcome();

        int shapeChoice = printShapeMenu();

        switch (shapeChoice) {
        case 1:
            printf("Triangle selected.\n");
            float triangleSides[3] = { 0 };
            printf("Enter the three sides of the triangle: ");
            scanf("%f %f %f", &triangleSides[0], &triangleSides[1], &triangleSides[2]);

            char* result = analyzeTriangle(triangleSides[0], triangleSides[1], triangleSides[2]);

            printf("%s\n", result);

            free(result);
            break;
        case 0:
            continueProgram = false;
            break;
        default:
            printf("Invalid value entered.\n");
            break;
        }
    }
    return 0;
}
