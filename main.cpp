// Mike Hadley
// CS344 - Program 1

#include <iostream>
#include "ASet.h"
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
      
        char command = ' '; // Declare a variable to hold command input from the keyboard

        string name; // Declare strings to hold standard input
        string stringName;
        string name1, name2;

        map<string,Set<string> *> log; // Declare a map to hold all existing sets and their handles
        map<string,Set<string> *>::iterator itr; // Declare iterators to find certain sets
        map<string,Set<string> *>::iterator itr2;

        while(command != 'Q')
        {
                cout << "Please enter a command (C,A,D,E,I,N,U,Q):" << endl << ">";
                cin >> command;

                if(command == 'C')
                {
                        cin >> name; // Can we set a name to the object through a string?
                        itr = log.find(name); // Check to see if the name already exists
                        if(itr == log.end())
                        {
                                Set<string> * set = new ASet<string>(100); // Assume that no set will have more than 100 elements
                                log[name] = set; // Put the set in the map
                                cout << "The set " << name << " has been created" << endl;
                        }
                        else
                                cout << "That set name already exists" << endl;
                }
                if(command == 'A')
                {
                        cin >> name;
                        cin >> stringName;
                        itr = log.find(name);
                        if(itr != log.end())
                        {
                              if((itr->second)->Add(stringName)) // Add the string to the set
                                   cout << "The element " << "\"" << stringName << "\"" << " was successfully added to the set " << name << endl;
                        }
                        else
                                cout << "That set name does not exist" << endl;  
                }
                if(command == 'D')
                {
                        cin >> name;
                        cin >> stringName;
                        itr = log.find(name);
                        if(itr != log.end())
                        {
                             if((itr->second)->Delete(stringName))
                                  cout << "The element " << "\"" << stringName << "\"" << " has been removed from the set " << name << endl;// Delete the string
                        }
                        else
                                cout << "That set name does not exist" << endl;
                }
                if(command == 'E')
                {
                        cin >> name;
                        itr = log.find(name);
                        if(itr != log.end())
                        {
                      
                                if((itr->second)->isEmpty())
                                        cout << "The set " << name << " is empty" << endl;
                                else
                                        cout << "The set " << name << " is not empty" << endl;
                        }
                        else
                                cout << "That set name does not exist" << endl;
                }
                if(command == 'I')
                {
                        cin >> name;
                        cin >> stringName;
                        itr = log.find(name);
                        if(itr != log.end())
                        {
                                if((itr->second)->In(stringName))
                                        cout << "The element " << "\"" << stringName << "\"" << " is in the set " << name << endl;
                                else
                                        cout << "The element " << "\"" << stringName << "\"" << " is not in the set " << name << endl;
                        }
                        else
                                cout << "That set name does not exist" << endl;
                }
                if(command == 'N')
                {
                        cin >> name1;
                        cin >> name2; 
                        itr = log.find(name1);
                        if(itr != log.end())
                        {
                                itr2 = log.find(name2);
                                if(itr2 != log.end())
                                {
                                        string tmp;  
                                        int i = 0;
                                        while( i < (itr->second)->getNumberOfElements())
                                        {
                                                tmp = (*(itr->second))[i]; // Need to declare the operator [] as virtual so it can be seen by the base class pointer
                                                if(!((itr2->second)->In(tmp)))
                                                        (itr->second)->Delete(tmp); // If a string is deleted, don't increment i since the strings will be shifted down
                                                else
                                                        i++;
                                        }
                                }
                                else
                                        cout << "The second set name does not exist" << endl;
                        }
                        else
                                cout << "The first set name does not exist" << endl;
                }
                if(command == 'U')
                {
                        cin >> name1;
                        cin >> name2;
                        itr = log.find(name1);
                        if(itr != log.end())
                        {
                                itr2 = log.find(name2);
                                if(itr2 != log.end())
                                {
                                        string tmp;
                                        for(int i = 0; i < (itr2->second)->getNumberOfElements(); i++)
                                        {
                                                tmp = (*(itr2->second))[i]; // Need to declare the operator [] as virtual so it can be seen by the base class pointer
                                                (itr->second)->Add(tmp); // If there is an item already in the set, an error message will show...
                                        }
                                }
                                else
                                        cout << "The second set name does not exist" << endl; 
                        }
                        else
                                cout << "The first set name does not exist" << endl;                          
                }
                if(command == 'Q')
                {
                        cout << "Goodbye" << endl;
                }             
                              
        }

}
