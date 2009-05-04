// Mike Hadley
// CS344 - Program 1

#ifndef SET_H
#define SET_H
#include <iostream>

using namespace std;

template <class Element>
class Set // Abstract base
{
	public:
	virtual bool isEmpty() = 0; // Returns true iff the set has no elements.
	virtual bool In(const Element & x) = 0; // Returns true if the element x is in the set.
	virtual bool Add(const Element & x) = 0; // If the set is not full, then x is added to the set and true is returned, else false is returned.
	virtual bool Delete(const Element & x) = 0; // If x is in the set, then x is deleted and true is returned, else false is returned. 
	virtual int getNumberOfElements() = 0; // Public accessor method
	virtual Element operator[](int i) = 0;

};

#endif 
