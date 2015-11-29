#include "constant_values.h"

#ifndef COMPLEX_BOX
#define COMPLEX_BOX

void movePointUntilAdditionalConstraintBeFulfilled(Point*, int);
Point calculateCentroid(Point*, int);
Point setCentroidCoordinatorsToAcceptable();
double calculateCentroidCoordinator(Point*, int, int);
void movePointHalfWayToCentroid(Point*, Point);
double calculateHalfWayToCentroidCoordinator(double, double);
Point reflectPoint(Point*, int);
void moveMaxValuePointAtLastPosition(Point*, int);
int findPointIndexOfMaximumObjectiveFunctionValue(Point*, int);
Point generateReflectedPoint(Point, Point);
double calculateReflectedPointCoordinator(double, double);
bool isReflectedPointFulfillConstraints(Point);
bool isValueOfReflectedPointLessThanMaxValue(Point, Point*, int);
void replaceMaxValuePointWithReflectedPoint(Point, Point*, int);
void movePointUntilAllConstraintsBeFulfilled(Point*, Point);

void printPoints2(Point points[], int numberOfPoints);
void printDoubleGroup2(double group[], int numberOfElements);

#endif
