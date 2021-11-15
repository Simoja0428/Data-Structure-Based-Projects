//
//  BoggleDie.cpp
//  BoggleAssignment
//
//  Created by Jacob  Simonek on 11/27/20.
//

#include "BoggleDie.hpp"

#include <iostream>
#include <algorithm> //For transform function

using namespace std;

BoggleDie :: BoggleDie(string sides[6])
{
    rolledValue = sides[rand() % 6];
}

string BoggleDie :: getRolledValue()
{
    return rolledValue;
}

void BoggleDie :: allCaps()
{
    transform(rolledValue.begin(), rolledValue.end(), rolledValue.begin(), ::toupper);
}
