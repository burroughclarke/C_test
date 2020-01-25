
#include "shape.h"

#ifndef SQUARE_C
#define SQUARE_C

class Square {

public:
	// https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c
	// virtual results in 'late binding' (vs 'early binding')
	int getNumberOfSides();
};

#endif