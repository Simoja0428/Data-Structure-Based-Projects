//
//  BoggleBoard.hpp
//  BoggleAssignment
//
//  Created by Jacob  Simonek on 11/27/20.
//

#pragma once

#include <iostream>

#include "BoggleDie.hpp"
#include "Trie.hpp"
#include "SafeArray.hpp"

using namespace std;

class BoggleBoard
{
public:
    BoggleBoard(const string& dictionaryPath); //Constructor
    ~BoggleBoard(); //Deconstructor
    void printBoard(); //Prints the board
    void allCaps(); //Converts dice to all caps since trie is all caps
    void solve(); //Recursive function calls on solve helper
    Trie getTrie(); //Function not in use as number of elements was optional
    
private:
    BoggleDie* board[5][5]; //Board is a 2D 5x5 array of BoggleDie pointers
    Trie trie; //Trie holds dictionary values
    void solveHelper(const string& wordSoFar, int x, int y, SafeArray<string> prevDie);
    SafeArray<string> duplicateFilter; //Used for words that can be made more than once
};
