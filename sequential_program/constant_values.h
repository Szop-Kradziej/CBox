#ifndef CONSTANT_VALUES
#define CONSTANT_VALUES

#define LOWER_POINT_BOUNDARY -2
#define UPPER_POINT_BOUNDARY 4
#define ALPHA 1.3
#define EPSILON 1
#define NUMBER_OF_COORDINATORS 5

#define MAX_TRY_OF_MOVE_POINT 10

typedef int bool;
#define true  1
#define false 0

typedef struct Point{
	double coordinators[NUMBER_OF_COORDINATORS];
	double objectiveFunctionValue;
} Point;

#endif
