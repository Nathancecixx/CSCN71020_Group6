#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "rectangleSolver.h"

bool is_Recatngle(POINT* arrOfPoint) {
	//If any of the sides are not 90*, return false
	if (!is_Orthoginal(arrOfPoint[0], arrOfPoint[1], arrOfPoint[2]) ) {
		//fprintf(stderr, "ERROR1: Problem with angle at X: %d   Y:%d", arrOfPoint[1].x, arrOfPoint[1].y);
		return false;
	}

	if (!is_Orthoginal(arrOfPoint[1], arrOfPoint[2], arrOfPoint[3])) {
		//fprintf(stderr, "ERROR2: Problem with angle at X: %d   Y:%d", arrOfPoint[2].x, arrOfPoint[2].y);
		return false;
	}

	if (!is_Orthoginal(arrOfPoint[2], arrOfPoint[3], arrOfPoint[0])) {
		//fprintf(stderr, "ERROR3: Problem with angle at X: %d   Y:%d", arrOfPoint[3].x, arrOfPoint[3].y);
		return false;
	}

	//Get Side lenghts for each side and store in a local variable
	int RightSideL = get_Distance(arrOfPoint[0], arrOfPoint[1]);
	int LeftSideL = get_Distance(arrOfPoint[2], arrOfPoint[3]);
	int TopSideL = get_Distance(arrOfPoint[0], arrOfPoint[3]);
	int BottomSideL = get_Distance(arrOfPoint[1], arrOfPoint[2]);

	//If opposite side lengths arent the same, or if all the side length are the same,
	//then the points do not form a rectangle. return false.
	if (RightSideL != LeftSideL || TopSideL != BottomSideL || RightSideL == TopSideL) {
		fprintf(stderr, "ERROR: problem with sidelengths");
		return false;
	}

	return true;
}

int get_Peram(POINT* arrOfPoints) {
	int SideLengthOne = get_Distance(arrOfPoints[0], arrOfPoints[1]);
	int SideLengthTwo = get_Distance(arrOfPoints[1], arrOfPoints[2]);

	return (SideLengthOne * 2) + (SideLengthTwo * 2);

}
int get_Area(POINT* arrOfPoints) {
	int SideLengthOne = get_Distance(arrOfPoints[0], arrOfPoints[1]);
	int SideLengthTwo = get_Distance(arrOfPoints[1], arrOfPoints[2]);

	return (SideLengthOne * SideLengthTwo);
}

int get_Distance(POINT pointA, POINT pointB) {
	//Returns the distance between 2 points using pythagrean theorem
	return (int) sqrt(pow((pointA.x - pointB.x), 2) + pow((pointA.y - pointB.y), 2));
}

bool is_Orthoginal(POINT pointA, POINT pointB, POINT pointC) {
	//Does the dot product and rturns true if the angle at B is 90*
	if ((pointB.x - pointA.x) * (pointB.x - pointC.x) + (pointB.y - pointA.y) * (pointB.y - pointC.y) == 0)
		return true;
	else
		return false;
}

void SortPoints(POINT* arrOfPoints) {

	//Sort X values highest to lowest
	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 4; j++) {
			//If arr i's x is greater than arr j's x, swap
			if (arrOfPoints[j].x > arrOfPoints[i].x) {
				//Store Point[i] in tmp
				int tmpX = arrOfPoints[i].x;
				int tmpY = arrOfPoints[i].y;
				//Set point[i] to point[j]
				arrOfPoints[i].x = arrOfPoints[j].x;
				arrOfPoints[i].y = arrOfPoints[j].y;
				//Set point[j] to tmp
				arrOfPoints[j].x = tmpX;
				arrOfPoints[j].y = tmpY;
			}
		}
	}

	//The array of 4 points should now be sorted Greatest to least
	//Now that its sorted on the X axis, 
	//Two things need to happen:
	//1) the 2 furthest right on the x axis need to be sorted from greatest to least.
	//2) The 2 furthest left need to be sorted from least to greatest.

	//1) 
	if (arrOfPoints[0].y < arrOfPoints[1].y) {
		//Store Point 1's values in tmp
		int tmpX = arrOfPoints[0].x;
		int tmpY = arrOfPoints[0].y;
		//Swap point 1's and point 2's values
		arrOfPoints[0].x = arrOfPoints[1].x;
		arrOfPoints[0].y = arrOfPoints[1].y;
		//Swap point 2's and tmp (point 1) values
		arrOfPoints[1].x = tmpX;
		arrOfPoints[1].y = tmpY;
	}

	//2)
	if (arrOfPoints[2].y > arrOfPoints[3].y) {
		//Store Point 3's values in tmp
		int tmpX = arrOfPoints[2].x;
		int tmpY = arrOfPoints[2].y;
		//Swap point 3's and point 4's values
		arrOfPoints[2].x = arrOfPoints[3].x;
		arrOfPoints[2].y = arrOfPoints[3].y;
		//Swap point 4's and tmp (point 3) values
		arrOfPoints[3].x = tmpX;
		arrOfPoints[3].y = tmpY;
	}

}