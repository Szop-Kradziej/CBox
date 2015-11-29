#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "random_number_generator.h"
#include "complex_box.h"
#include "problem_definition.h"

void generatePointsInBounduaries(Point startPoints[], int numberOfPoints) {
	int i ;
	
	for(i = 0; i < numberOfPoints; i++)
	{
		generateCoordinatorsInBounduaries(startPoints[i].coordinators);
		if(isAdditionalConstraintFulfilled(startPoints[i].coordinators)) {
		//	printf("Yeap! fulfilled\n");
		}
		else {
		//	printf("Nope\n");
			movePointUntilAdditionalConstraintBeFulfilled(startPoints,i);
		}
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
