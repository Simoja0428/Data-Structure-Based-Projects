//
//  TrieElement.hpp
//  BoggleAssignment
//
//  Created by Jacob  Simonek on 11/27/20.
//


#pragma once

#include <iostream>
#include "SafeArray.hpp"

using namespace std;

class TrieElement //Class for TrieElement
{
public:
    TrieElement(string word); //Constructor
    ~TrieElement(); //Deconstructor
    void insertHelper(string word); //Recursive insertHelper
    string searchHelper(const string& word); //Recursive searchHelper
    void printHelper(); //Recursive printHelper
    int getNumElements(); //Function not in use as it was optional
    
protected:
    SafeArray<TrieElement*> p_letters; //SafeArray of 26 TrieElement Pointers
    bool isWordComplete; //Bool says whether its a full word or not
    string wordSoFar; //Holds the value of the word
    int numElements; //Variable not in use as it was optional
};
