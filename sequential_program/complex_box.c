#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "complex_box.h"
#include "problem_definition.h"

void movePointUntilAdditionalConstraintBeFulfilled(Point points[], int pointIndex) {
	Point centroid;
	int i;
	
	centroid = calculateCentroid(points, pointIndex);
	
	i = 0;
	while(!isAdditionalConstraintFulfilled(points[pointIndex].coordinators) && i < MAX_TRY_OF_MOVE_POINT) {
		movePointHalfWayToCentroid(&points[pointIndex], centroid);
		printf("\nWHILEcorr: %lf \n", points[pointIndex].coordinators[1]);
		i++;
	}
}

Point calculateCentroid(Point points[], int pointIndex) {
	Point centroid;
	int i;
	
	if(pointIndex == 0) {
		centroid = setCentroidCoordinatorsToAcceptable();
		return centroid;
	}
	
	for(i = 0; i < NUMBER_OF_COORDINATORS; i++) {
		centroid.coordinators[i] = calculateCentroidCoordinator(points, pointIndex, i);
	}
	
	return centroid;
}

Point setCentroidCoordinatorsToAcceptable() {
	Point centroid;
	int i;
	
	// Sum is equal to 0
	for(i = 0; i < NUMBER_OF_COORDINATORS; i++) {
		centroid.coordinators[i] = i + 1;
	}
	
	return centroid;
}

double calculateCentroidCoordinator(Point points[], int numberOfAcceptedPoints, int coordinatorIndex) {
	double sum, centroidCoordinator;
	int i;
	sum = 0.0;
	
	for(i = 0; i < numberOfAcceptedPoints; i++) {
		sum += points[i].coordinators[coordinatorIndex];
	}
	
	centroidCoordinator = sum / numberOfAcceptedPoints;
	
	return centroidCoordinator;
}

void movePointHalfWayToCentroid(Point* point, Point centroid) {
	int i;
	
	for(i = 0; i < NUMBER_OF_COORDINATORS; i++) {
		point->coordinators[i] = calculateHalfWayToCentroidCoordinator(point->coordinators[i], centroid.coordinators[i]);
	}
}

double calculateHalfWayToCentroidCoordinator(double coordinator, double centroidCoordinator) {
	return (coordinator + centroidCoordinator) / 2;
}

Point reflectPoint(Point points[], int numberOfPoints) {
	Point centroid, reflectedPoint;
	int indexOfLastPoint;
	indexOfLastPoint = numberOfPoints - 1;
	
	moveMaxValuePointAtLastPosition(points, numberOfPoints);
	centroid = calculateCentroid(points, indexOfLastPoint);
	reflectedPoint = generateReflectedPoint(points[indexOfLastPoint], centroid);
	reflectedPoint.objectiveFunctionValue = calculateObjectiveFunctionValue(reflectedPoint.coordinators);
	
	if(isReflectedPointFulfillConstraints(reflectedPoint)) {
		printf("Reflected point fulfill constraints \n ");
		if(isValueOfReflectedPointLessThanMaxValue(reflectedPoint, points, indexOfLastPoint)) {
			replaceMaxValuePointWithReflectedPoint(reflectedPoint, points, indexOfLastPoint);
		}
		else {
			printf("Generate new with with alfa reduced\n");
		}
	}
	else {
		printf("Oh no reflected point do not fulfill constraints\n");
		movePointUntilAllConstraintsBeFulfilled(&reflectedPoint, centroid);
		printf("\nReflectedPoint: %lf \n", reflectedPoint.coordinators[1]);
	}
	
	return reflectedPoint;
}

void moveMaxValuePointAtLastPosition(Point points[], int numberOfPoints) {
	int maxValueIndex;
	Point temp;
	
	maxValueIndex = findPointIndexOfMaximumObjectiveFunctionValue(points, numberOfPoints);
	
	temp = points[maxValueIndex];
	points[maxValueIndex] = points[numberOfPoints - 1];
	points[numberOfPoints - 1] = temp;
}

int findPointIndexOfMaximumObjectiveFunctionValue(Point points[], int numberOfPoints) {
	int maxValueIndex, i;
	maxValueIndex = 0;
	
	for(i = 1; i < numberOfPoints; i++) {
		if(points[i].objectiveFunctionValue > points[maxValueIndex].objectiveFunctionValue) {
			maxValueIndex = i;
		}
	}
	
	return maxValueIndex;
}

Point generateReflectedPoint(Point maxValuePoint, Point centroid) {
	Point reflectedPoint;
	int i;
	
	for(i = 0; i < NUMBER_OF_COORDINATORS; i++) {
		reflectedPoint.coordinators[i] = calculateReflectedPointCoordinator(maxValuePoint.coordinators[i],centroid.coordinators[i]);
	}
	
	return reflectedPoint;
}

double calculateReflectedPointCoordinator(double maxValueCoordinator, double centroidCoordinator) {
	return (1 + ALPHA)*centroidCoordinator - ALPHA*maxValueCoordinator;
}

bool isReflectedPointFulfillConstraints(Point reflectedPoint) {
	if(isPointInBounduaries(reflectedPoint) && isAdditionalConstraintFulfilled(reflectedPoint.coordinators)) {
		return true;
	}
	return false;
}
bool isValueOfReflectedPointLessThanMaxValue(Point reflectedPoint, Point points[], int indexOfMaxValuePoint) {
	if(reflectedPoint.objectiveFunctionValue < points[indexOfMaxValuePoint].objectiveFunctionValue) {
		return true;
	}
	return false;
}
void replaceMaxValuePointWithReflectedPoint(Point reflectedPoint, Point points[], int indexOfMaxValuePoint) {
	points[indexOfMaxValuePoint] = reflectedPoint;
}

void movePointUntilAllConstraintsBeFulfilled(Point* reflectedPoint, Point centroid) {
	int i;

	i = 0;
	while(((!isAdditionalConstraintFulfilled(reflectedPoint->coordinators)) || (!isPointInBounduaries(*reflectedPoint))) && i < MAX_TRY_OF_MOVE_POINT) {
		movePointHalfWayToCentroid(reflectedPoint, centroid);
		printf("\nWHILEReflectedPoint: %lf \n", reflectedPoint->coordinators[1]);
		i++;
	}
}
