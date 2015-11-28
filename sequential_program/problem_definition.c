#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "problem_definition.h"

void calculatePointsObjectiveFunctionValue(Point points[], int numberOfPoints, double objectiveFunctionValues[]) {
	int i;
	 
	for(i = 0; i < numberOfPoints; i++) {
		objectiveFunctionValues[i] = calculateObjectiveFunctionValue(points[i].coordinators);
	}
}

double calculateObjectiveFunctionValue(double coordinators[]) {
	int i;
	double objectiveFunctionValue = 0;
	
	// Sum up from 1 to n-1;
	for(i = 0; i < NUMBER_OF_COORDINATORS - 1; i++) {
		objectiveFunctionValue += 100 * pow((coordinators[i + 1] - pow(coordinators[i], 2)), 2) + pow((1 - coordinators[i]), 2);
	}
	return objectiveFunctionValue;
}
/*
bool isAdditionalConstraintFulfilled(Point points[], int numberOfPoints) {
	double leftSideAdditionalConstraintValue;
	
	leftSideAdditionalConstraintValue = calculateLeftSideOfAdditionalConstraint(points, numberOfPoints);
	if(leftSideAdditionalConstraintValue <= 10 * numberOfPoints) {
		return true;
	}
	return false;
}

double calculateLeftSideOfAdditionalConstraint(Point points[], int numberOfPoints) {
	int i;
	double leftSideAdditionalConstraintValue = 0;
	
	for(i = 0; i < numberOfPoints; i++) {
		leftSideAdditionalConstraintValue += pow((points[i].x - i), 2);
	}
	
	return leftSideAdditionalConstraintValue;
}*/
