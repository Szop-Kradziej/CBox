#include "constant_values.h"

#ifndef COMPLEX_BOX
#define COMPLEX_BOX

void movePointUntilAdditionalConstraintBeFulfilled(Point*, int);
Point calculateCentroid(Point*, int);
Point setCentroidCoordinatorsToAcceptable();
double calculateCentroidCoordinator(Point*, int, int);
void movePointHalfWayToCentroid(Point*, Point);
double calculateHalfWayToCentroidCoordinator(double, double);

#endif
