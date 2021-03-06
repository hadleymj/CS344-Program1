// Mike Hadley
// CS344- Program 1

#ifndef ASET_H
#define ASET_H
#include <iostream>
#include "Set.h"

using namespace std;

template <class Element>
class ASet: public Set<Element>
{
        public:
                ASet() // Default constructor
                {}
        	ASet(int containerSize) // Overloaded constructor
                {
                        size = containerSize;
                        ptr = new Element[size];
                        numberOfElements = 0;
                }
	
        	// Don't need to declare the overridden functions as virtual

        	bool isEmpty()
                {
                         if(numberOfElements == 0)
              			  return true;
                         else
              			  return false;
                } // Returns true iff the set has no elements.

                int getNumberOfElements()
                {
                        return numberOfElements;
                } // Public accessor method

                bool In(const Element & x)
                { 
                        for ( int i = 0; i < numberOfElements; i++)
                        {
                        	 if((ptr[i].compare(x)) == 0)
                       			 return true;
                        }
                       		 return false;
                } // Returns true if the element x is in the set.

                bool Add(const Element & x)
                {
                            	if(numberOfElements != size) // Make sure that the set is not full
                                {
                                        if(this->In(x)) // Make sure that the element is not already in the set
                                        {
                                            cout << "The element " << "\"" << x << "\"" << " is already in the set. No duplicates are allowed." << endl;
                                            return false;
                                        }
                                        else
                                        {
                      				  ptr[numberOfElements] = x;
                       				  numberOfElements++;
                        			  return true;
                                        }
                                }
                                else
                                {
                                                cout << "The set is full, cannot add any more elements." << endl;
                                                return false;
                                }
                }       // If the set is not full, then x is added to the set and true is returned, else false is returned.

                bool Delete(const Element & x)
                {
                        if(this->In(x))
                        {
               			 for ( int i = 0; i < numberOfElements; i++) // Don't have to worry about getting rid of duplicate items: they are not allowed.
              			  {
                    			    if(ptr[i] == x) // Need to delete, and then move everything over
                     			   {
                              			   ptr[i] = ""; // Avoid using NULL
                             			   for(int j = i; j < (numberOfElements - 1); j++) // Shift everything over
                               			   {
                                      			  ptr[j] = ptr[j+1];
                                      			  ptr[j+1] = ""; // Delete the element that has been shifted from the original position
                               		           }
                               			   numberOfElements--;
                              			   return true;
                       			   }
             		          }
                         }
                         else
                         {
                		cout << "The element " << "\"" << x << "\"" << " is not in the set. Cannot be deleted" << endl;
               		        return false;
                         }
               
                } // If x is in the set, then x is deleted and true is returned, else false is returned.

       	        Element operator[](int i)
                {      
                        Element elem = ptr[i];
                        return elem;
                } //  Support random-access, only allow access to private members through public accessor methods
      
        private:

        Element * ptr; // Pointer to a memory array
        int numberOfElements; // Specifies the actual number of elements in the set
        int size; // Specifies the size allocated in memory

};

#endif

