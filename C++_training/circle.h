
#include "shape.h"

#ifndef CIRCLE_C
#define CIRCLE_C

class Circle : Shape {

public:
	// https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c
	// virtual results in 'late binding' (vs 'early binding')
	int getNumberOfSides();
};

#endif