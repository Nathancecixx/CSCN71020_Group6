#pragma once

#include<stdbool.h>

typedef struct point {
	int x;
	int y;
}POINT;

bool is_Recatngle(POINT* arrOfPoints);
int get_Peram(POINT* arrOfPoints);
int get_Area(POINT* arrOfPoints);
int get_Distance(POINT pointA, POINT pointB);
bool is_Orthoginal(POINT pointA, POINT pointB, POINT pointC);
void SortPoints(POINT* arrOfPoints);