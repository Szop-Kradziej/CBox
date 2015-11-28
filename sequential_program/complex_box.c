#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "complex_box.h"

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
		printf("corr: %lf \n", point->coordinators[i]);
	}
}

double calculateHalfWayToCentroidCoordinator(double coordinator, double centroidCoordinator) {
	return (coordinator + centroidCoordinator) / 2;
}

Point reflectPoint(Point points[], int numberOfPoints) {
	Point centroid, reflectedPoint;
	int indexOfMaxValuePoint;
	
	indexOfMaxValuePoint = findPointIndexOfMaximumObjectiveFunctionValue(points, numberOfPoints);
	centroid = calculateCentroidExpectPointOfMaxValue(points, numberOfPoints, indexOfMaxValuePoint);
	reflectedPoint = generateReflectedPoint(points[indexOfMaxValuePoint], centroid);
	
	return reflectedPoint;
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

Point calculateCentroidExpectPointOfMaxValue(Point points[], int numberOfPoints, int indexOfMaxValuePoint)
{
	Point centroid;
	int i;

	for(i = 0; i < NUMBER_OF_COORDINATORS; i++) {
		centroid.coordinators[i] = calculateCentroidCoordinatorExpectPointOfMaxValue(points, numberOfPoints, i, indexOfMaxValuePoint);
	}
	
	return centroid;
}

double calculateCentroidCoordinatorExpectPointOfMaxValue(Point points[], int numberOfPoints, int coordinatorIndex, int indexOfMaxValuePoint) {
	double sum, centroidCoordinator;
	int i;
	sum = 0.0;
	
	for(i = 0; i < numberOfPoints; i++) {
		sum += points[i].coordinators[coordinatorIndex];
	}
	
	sum -= points[indexOfMaxValuePoint].coordinators[coordinatorIndex];
	
	centroidCoordinator = sum / (numberOfPoints - 1);
	
	return centroidCoordinator;
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
