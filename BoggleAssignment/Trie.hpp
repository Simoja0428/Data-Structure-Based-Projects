//
//  Trie.hpp
//  BoggleAssignment
//
//  Created by Jacob  Simonek on 11/28/20.
//

#pragma once

#include <iostream>
#include "TrieElement.hpp"

using namespace std;

class Trie //Class for the Trie Structure
{
public:
    Trie(const string& filepath); //Constructor
    ~Trie(); //Deconstructor
    string search(const string& word); //Search method Recursive
    void printAllWords(); //Print method recursive
    int getTrieElements(); //Not implemented it was optional
    
private:
    TrieElement* p_root;
};

