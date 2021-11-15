//
//  Trie.hpp
//  Trie
//
//  Created by Jacob  Simonek on 11/22/20.
//

#pragma once

#include <iostream>
#include "TrieElement.hpp"

using namespace std;

class Trie //Class for the Trie Structure
{
public:
    Trie(const string& filepath);
    ~Trie();
    string search(const string& word);
    void printAllWords();
    
    
private:
    TrieElement* p_root;
};
