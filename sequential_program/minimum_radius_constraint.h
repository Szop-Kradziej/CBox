#include "constant_values.h"

#ifndef MINIMUM_RADIUS_CONSTRAINT
#define MINIMUM_RADIUS_CONSTRAINT

#define MAX_NUMBER_OF_EXTREME_CANDIDATES 4

bool isMinimumRadiusConstraintFulfiled(Point*, int);
double findMinimumRadius(Point*);
void findPointsWithExtremeCoordinates(Point*, Point*);
void setAllExtremeCoordinatesToValueOfPoint(Point* , Point); 
bool isRadiusLessThanEpsilon(double);

#endif
