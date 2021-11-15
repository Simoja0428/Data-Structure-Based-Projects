//
//  BoggleDie.hpp
//  BoggleAssignment
//
//  Created by Jacob  Simonek on 11/27/20.
//

#pragma once

#include <iostream>

using namespace std;

class BoggleDie //Class for BogglDie
{
public:
    BoggleDie(string sides[6]); //Constructor
    string getRolledValue(); //Returns the random rolled value
    void allCaps(); //Converts to all caps since trie is in all caps
    
private:
    string rolledValue; //Holds random rolled value
};
