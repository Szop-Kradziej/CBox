#include <stdlib.h>
#include <stdio.h>

typedef int bool;
#define true  1
#define false 0

int getInputArgument(int, char**);
bool isInputArgumentSet(int argc);

int main(int argc, char* argv[]) {
	
	int numberOfPolyhedronPoints;
	
	numberOfPolyhedronPoints = getInputArgument(argc, argv);
	printf("Number of polyhedron points: %d\n", numberOfPolyhedronPoints);
	
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

