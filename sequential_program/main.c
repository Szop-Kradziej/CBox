#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "constant_values.h"
#include "random_number_generator.h"
//#include "minimum_radius_constraint.h"
#include "problem_definition.h"

int getInputArgument(int, char**);
bool isInputArgumentSet(int);
void computeComplexBoxSolution(int);
void printPoints(Point*, int);
void printDoubleGroup(double*, int);

int main(int argc, char* argv[]) {
	
	int numberOfPolyhedronPoints;
	srand(time(NULL));
	
	numberOfPolyhedronPoints = getInputArgument(argc, argv);
	computeComplexBoxSolution(numberOfPolyhedronPoints);
	
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

void computeComplexBoxSolution(const int numberOfPolyhedronPoints) {
	Point startPoints[numberOfPolyhedronPoints];
	double objectiveValues[numberOfPolyhedronPoints];
	
	generatePointsInBounduaries(startPoints, numberOfPolyhedronPoints);
	
	printPoints(startPoints, numberOfPolyhedronPoints);
	calculatePointsObjectiveFunctionValue(startPoints, numberOfPolyhedronPoints, objectiveValues);
	printDoubleGroup(objectiveValues, numberOfPolyhedronPoints);
	
	/*
	if(isMinimumRadiusConstraintFulfiled(startPoints, numberOfPolyhedronPoints)) {
		printf("MRCF: fulfiled");
		exit(0);
	}*/
}

void printPoints(Point points[], int numberOfPoints) {
	int i;
	
	for(i = 0; i < numberOfPoints; i++) {
		printf("Point number: %d \n", i);
		printDoubleGroup(points[i].coordinators, NUMBER_OF_COORDINATORS);
	}
}

void printDoubleGroup(double group[], int numberOfElements) {
	int i;
	
	for(i = 0; i < numberOfElements; i++) {
		printf("%lf, ", group[i]);
	}
	printf("\n");
}
