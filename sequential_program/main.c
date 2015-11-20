#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "constant_values.h"
#include "random_number_generator.h"

int getInputArgument(int, char**);
bool isInputArgumentSet(int argc);

int main(int argc, char* argv[]) {
	
	int numberOfPolyhedronPoints;
	Point *points;
	srand(time(NULL));
	
	numberOfPolyhedronPoints = getInputArgument(argc, argv);
	points = generatePointsInBounduaries(numberOfPolyhedronPoints);
	
	return 0;
}

int getInputArgument(int argc, char** argv) {
	
	const int ARGUMENT_POSITION = 1;
	int inputArgument;
	
	if(isInputArgumentSet(argc) == false) {
		printf("You need to set number of polyhedron points!\n");
		exit(0);
	}
	inputArgument = atoi(argv[ARGUMENT_POSITION]);
	
	return inputArgument;
}

bool isInputArgumentSet(int argc) {
	
	if(argc > 1) {
		return true;
	}
	return false;
}

