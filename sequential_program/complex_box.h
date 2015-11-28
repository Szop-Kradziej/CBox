#include "constant_values.h"

#ifndef COMPLEX_BOX
#define COMPLEX_BOX

void movePointUntilAdditionalConstraintBeFulfilled(Point*, int);
Point calculateCentroid(Point*, int);
double calculateCentroidCoordinator(Point*, int, int);
void movePointHalfWayToCentroid(Point*, Point);

#endif
