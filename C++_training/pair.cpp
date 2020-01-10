#include "pair.h"

int operator +(const MyPair& amount1, const MyPair& amount2) {
	// Pair temp;
	return amount1.one + amount1.two + amount2.one + amount2.two;
}

MyPair::MyPair(int mOne, int mTwo) {
	one = mOne;
	two = mTwo;
}

// destructor
// why virtual: a derived class created using a pointer to a base class...
// then calling a non-virtual destructor is undefined behaviour
MyPair::~MyPair() {
	// ???
}

