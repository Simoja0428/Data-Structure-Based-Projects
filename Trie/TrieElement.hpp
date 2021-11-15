//
//  TrieElement.hpp
//  Trie
//
//  Created by Jacob  Simonek on 11/22/20.
//

#pragma once

#include <iostream>
#include "SafeArray.hpp"

using namespace std;

class TrieElement
{
public:
    TrieElement(string word);
    ~TrieElement();
    void insertHelper(string word);
    string searchHelper(const string& word);
    void printHelper();
    
protected:
    SafeArray<TrieElement*> p_letters;
    bool isWordComplete;
    string wordSoFar;
};
