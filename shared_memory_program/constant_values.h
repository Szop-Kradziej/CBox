#ifndef CONSTANT_VALUES
#define CONSTANT_VALUES

#define LOWER_POINT_BOUNDARY -40
#define UPPER_POINT_BOUNDARY 40
#define ALPHA 1.3
#define ALPHA_ACCURACY 0.001
#define DISTANCE_EPSILON 5
#define NUMBER_OF_COORDINATORS 10

#define MAX_TRY_OF_MOVE_POINT 100
#define MAX_TRY_OF_REFLECTED_POINT 100
#define MAX_PROGRAM_ITERATIONS 10000000000

typedef int bool;
#define true  1
#define false 0

typedef struct Point{
	double coordinators[NUMBER_OF_COORDINATORS];
	double objectiveFunctionValue;
} Point;

#endif
