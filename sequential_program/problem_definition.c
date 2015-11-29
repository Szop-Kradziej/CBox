#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "problem_definition.h"

void calculatePointsObjectiveFunctionValue(Point points[], int numberOfPoints) {
	int i;
	 
	for(i = 0; i < numberOfPoints; i++) {
		points[i].objectiveFunctionValue = calculateObjectiveFunctionValue(points[i].coordinators);
	}
}

double calculateObjectiveFunctionValue(double coordinators[]) {
	int i;
	double objectiveFunctionValue = 0;
	
	// Sum up from 1 to n-1 -> 0 to n-2
	for(i = 0; i < NUMBER_OF_COORDINATORS - 1; i++) {
		objectiveFunctionValue += 100 * pow((coordinators[i + 1] - pow(coordinators[i], 2)), 2) + pow((1 - coordinators[i]), 2);
	}
	return objectiveFunctionValue;
}

bool isAdditionalConstraintFulfilled(double coordinators[]) {
	double leftSideAdditionalConstraintValue;
	
	leftSideAdditionalConstraintValue = calculateLeftSideOfAdditionalConstraint(coordinators);
	//printf("\nLeft side %lf\n", leftSideAdditionalConstraintValue);
	if(leftSideAdditionalConstraintValue <= 10 * NUMBER_OF_COORDINATORS) {
		return true;
	}
	return false;
}

double calculateLeftSideOfAdditionalConstraint(double coordinators[]) {
	int i;
	double leftSideAdditionalConstraintValue = 0;
	
	for(i = 0; i < NUMBER_OF_COORDINATORS; i++) {
		// Sum up from 1 to n:
		leftSideAdditionalConstraintValue += pow((coordinators[i] - (i + 1)), 2);
	}
	return leftSideAdditionalConstraintValue;
}

bool isPointInBounduaries(Point point) {
	int i;
	for(i = 0; i < NUMBER_OF_COORDINATORS; i++) {
		if(!isCoordinatorInBounduaries(point.coordinators[i])) {
			return false;
		}
	}
	return true;
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
