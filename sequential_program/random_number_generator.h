#include "constant_values.h"

#ifndef RANDOM_NUMBER_GENERATOR
#define RANDOM_NUMBER_GENERATOR

void generatePointsInBounduaries(Point startPoints[], int numberOfPoints);
void generateCoordinatorsInBounduaries(double*);
double generateCoordinatorInBounduaries();
double generateNumberInBoundaries();
bool isCoordinatorInBounduaries(double);
bool isNumberInBounduaries(double);

#endif
