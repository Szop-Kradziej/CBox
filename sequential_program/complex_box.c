#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "complex_box.h"

void movePointUntilAdditionalConstraintBeFulfilled(Point points[], int pointIndex) {
	Point centroid;
	int i;
	
	centroid = calculateCentroid(points, pointIndex);
	
	i = 0;
	while(!isAdditionalConstraintFulfilled(points[pointIndex].coordinators) && i < 5) {
		movePointHalfWayToCentroid(&points[pointIndex], centroid);
		i++;
	}
}

Point calculateCentroid(Point points[], int pointIndex) {
	Point centroid;
	int i;
	
	for(i = 0; i < NUMBER_OF_COORDINATORS; i++) {
		centroid.coordinators[i] = calculateCentroidCoordinator(points, pointIndex, i);
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
}
