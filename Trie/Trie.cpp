//
//  Trie.cpp
//  Trie
//
//  Created by Jacob  Simonek on 11/22/20.
//

#include "Trie.hpp"

#include <algorithm> //For tranform to lower case functin
#include <iostream>
#include <fstream>

using namespace std;

Trie :: Trie(const string& filePath)
{
    p_root = new TrieElement("");
    
    ifstream file;
    file.open(filePath);
    
    string word;
    file >> word;
    
    while (file.good())
    {
        transform(word.begin(), word.end(), word.begin(),::toupper);
        p_root -> insertHelper(word);
        file >> word;
    }
}

Trie :: ~Trie()
{
    delete p_root;
}

string Trie :: search(const string& word)
{
    return p_root->searchHelper(word);
}

void Trie :: printAllWords()
{
    p_root->printHelper();
}
