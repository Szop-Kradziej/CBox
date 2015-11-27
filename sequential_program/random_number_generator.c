#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "random_number_generator.h"

void generatePointsInBounduaries(Point startPoints[], int numberOfPoints) {
	int i ;
	
	for(i = 0; i < numberOfPoints; i++)
	{
		startPoints[i] = generatePointInBounduaries();
		printf("point: %lf, %lf\n", startPoints[i].x, startPoints[i].y);
	}
}

Point generatePointInBounduaries() {
	Point point;
	point.x = generateNumberInBoundaries();
	point.y = generateNumberInBoundaries();
	
	return point;
}

double generateNumberInBoundaries() {
	double randomNumber;
	randomNumber = LOWER_POINT_BOUNDARY + (UPPER_POINT_BOUNDARY - LOWER_POINT_BOUNDARY)*(rand()/(double)RAND_MAX);
	
	return randomNumber;
}

bool isPointInBounduaries(Point point) {
	if(isNumberInBounduaries(point.x) && isNumberInBounduaries(point.y)) {
		return true;
	}
	return false;
}

bool isNumberInBounduaries(double number) {
	if(LOWER_POINT_BOUNDARY<= number && number <= UPPER_POINT_BOUNDARY) {
		return true;
	}
	return false;
}
