#include "constant_values.h"

#ifndef PROBLEM_DEFINITION
#define PROBLEM_DEFINITION

void calculatePointsObjectiveFunctionValue(Point*, int);
double calculateObjectiveFunctionValue(double*);
bool isAdditionalConstraintFulfilled(double*);
double calculateLeftSideOfAdditionalConstraint(double*);
bool isPointInBounduaries(Point);
bool isCoordinatorInBounduaries(double);
bool isNumberInBounduaries(double);

#endif
