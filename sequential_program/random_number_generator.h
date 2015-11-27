#include "constant_values.h"

#ifndef RANDOM_NUMBER_GENERATOR
#define RANDOM_NUMBER_GENERATOR

void generatePointsInBounduaries(Point startPoints[], int numberOfPoints);
Point generatePointInBounduaries();
double generateNumberInBoundaries();
bool isPointInBounduaries(Point);
bool isNumberInBounduaries(double);

#endif
