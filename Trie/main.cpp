//
//  main.cpp
//  Trie
//
//  Created by Jacob  Simonek on 11/12/20.
//

#include "Trie.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Trie trie("bigDictionary.txt");
    
    cout<<"All words in the trie:"<<endl;
    trie.printAllWords();
    cout<<endl; 
    
    //search for some words
    cout<<trie.search("A")<<endl;
    cout<<trie.search("BA")<<endl;
    cout<<trie.search("CAR")<<endl;
    cout<<trie.search("CAT")<<endl;
    cout<<trie.search("CATHY")<<endl;
    return 0;
}
