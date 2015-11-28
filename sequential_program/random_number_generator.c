#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "random_number_generator.h"

void generatePointsInBounduaries(Point startPoints[], int numberOfPoints) {
	int i ;
	
	for(i = 0; i < numberOfPoints; i++)
	{
		generateCoordinatorsInBounduaries(startPoints[i].coordinators);
	}
}

void generateCoordinatorsInBounduaries(double coordinators[]) {
	int i;
	
	for(i = 0; i < NUMBER_OF_COORDINATORS; i++) {
		coordinators[i] = generateCoordinatorInBounduaries();
	}
}

double generateCoordinatorInBounduaries() {
	double coordinator;
	coordinator = generateNumberInBoundaries();
	return coordinator;
}

double generateNumberInBoundaries() {
	double randomNumber;
	randomNumber = LOWER_POINT_BOUNDARY + (UPPER_POINT_BOUNDARY - LOWER_POINT_BOUNDARY)*(rand()/(double)RAND_MAX);
	
	return randomNumber;
}

bool isCoordinatorInBounduaries(double coordinator) {
	if(isNumberInBounduaries(coordinator)) {
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
