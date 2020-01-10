#ifndef PAIR_H
#define PAIR_H

class MyPair {

	public:

		// you can also have friend CLASSES!
		friend int operator +(const MyPair& amount1, const MyPair& amount2);

		MyPair(int mOne, int mTwo);

		int one;
		int two;

		// destructor
		// why virtual: a derived class created using a pointer to a base class...
		// then calling a non-virtual destructor is undefined behaviour
		virtual ~MyPair();

	private:

};

#endif