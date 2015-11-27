#include <stdlib.h>
#include <stdio.h>
#include "minimum_radius_constraint.h"

bool isMinimumRadiusConstraintFulfiled(Point points[], int numberOfPolyhedronPoints) {
	double radius;
	radius = findMinimumRadius(points);
	return isRadiusLessThanEpsilon(radius);
}

double findMinimumRadius(Point points[]) {
	Point extremeCoordinates[MAX_NUMBER_OF_EXTREME_CANDIDATES];
	findPointsWithExtremeCoordinates(extremeCoordinates, points);
	return 0.5;
}

void findPointsWithExtremeCoordinates(Point extremeCoordinates[], Point points[]) {
	int i;
	setAllExtremeCoordinatesToValueOfPoint(extremeCoordinates, points[0]);
	
	for(i = 0; i < MAX_NUMBER_OF_EXTREME_CANDIDATES; i++) {
		printf("Ext pt x: %lf, y %lf\n", extremeCoordinates[i].x, extremeCoordinates[i].y);
	}
}

void setAllExtremeCoordinatesToValueOfPoint(Point* extremeCoordinates, Point point) {
	int i;
	for(i = 0; i < MAX_NUMBER_OF_EXTREME_CANDIDATES; i++) {
		extremeCoordinates[i].x = point.x;
		extremeCoordinates[i].y = point.y;
	}
}

bool isRadiusLessThanEpsilon(double radius) {
	if(radius < EPSILON) {
		return true;
	}
	return false;
}
