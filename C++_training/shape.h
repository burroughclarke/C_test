
#ifndef SHAPE_C
#define SHAPE_C

// C++ doesn't have 'interfaces' (Java does), they have 'virtual functions' and 'PURE virtual functions'


class Shape {

public:
	// https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c
	// virtual results in 'late binding' (vs 'early binding')
	// '= 0' is a PURE virtual function
	virtual int getNumberOfSides() = 0;
};

#endif