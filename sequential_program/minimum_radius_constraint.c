#include <stdlib.h>
#include <stdio.h>
#include "minimum_radius_constraint.h"

bool isMinimumRadiusConstraintFulfiled(Point* points) {
	double radius;
	radius = findMinimumRadius(points);
	return isRadiusLessThanEpsilon(radius);
}

double findMinimumRadius(Point* points) {
	return 0.5;
}

bool isRadiusLessThanEpsilon(double radius) {
	if(radius < EPSILON) {
		return true;
	}
	return false;
}
