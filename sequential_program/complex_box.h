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
Point generateReflectedPoint(Point, Point, double);
double calculateReflectedPointCoordinator(double, double, double);
bool isReflectedPointFulfillConstraints(Point);
bool isValueOfReflectedPointLessThanMaxValue(Point, Point*, int);
void replaceMaxValuePointWithReflectedPoint(Point, Point*, int);
void movePointUntilAllConstraintsBeFulfilled(Point*, Point);
bool isDistanceConditionFulfilled(Point*, int);
bool isTwoPointsDistanceConditionFullfiled(Point, Point);
double calculateDistanceBetweenTwoPoints(Point, Point);

#endif
