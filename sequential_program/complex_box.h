#include "constant_values.h"

#ifndef COMPLEX_BOX
#define COMPLEX_BOX

void movePointUntilAdditionalConstraintBeFulfilled(Point*, int);
Point calculateCentroid(Point*, int);
Point setCentroidCoordinatorsToAcceptable();
double calculateCentroidCoordinator(Point*, int, int);
void movePointHalfWayToCentroid(Point*, Point);
double calculateHalfWayToCentroidCoordinator(double, double);
int findPointIndexOfMaximumObjectiveFunctionValue(Point*, int);
Point reflectPoint(Point*, int);
Point calculateCentroidExpectPointOfMaxValue(Point*, int, int);
double calculateCentroidCoordinatorExpectPointOfMaxValue(Point*, int, int, int);
Point generateReflectedPoint(Point, Point);
double calculateReflectedPointCoordinator(double, double);

void printPoints2(Point points[], int numberOfPoints);
void printDoubleGroup2(double group[], int numberOfElements);

#endif
