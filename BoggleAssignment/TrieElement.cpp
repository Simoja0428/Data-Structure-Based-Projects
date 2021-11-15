//
//  TrieElement.cpp
//  BoggleAssignment
//
//  Created by Jacob  Simonek on 11/27/20.
//

#include "TrieElement.hpp"
#include "SafeArray.hpp"
#include <iostream>
#include <algorithm> //For transform() function

using namespace std;

TrieElement:: TrieElement(string word):
p_letters(26)
{
    isWordComplete = false;
    wordSoFar = word;
    
    for (int i = 0; i < 26; i++)
    {
        p_letters.push_back(NULL);
    }
}

TrieElement::~TrieElement()
{
    for (int i = 0; i < p_letters.size(); i++)
    {
        if (p_letters[i] != 0)
        {
            delete p_letters[i];
            p_letters[i] = 0;
        }
    }
}

void TrieElement:: insertHelper(string word)
{
    if (word.length() == 0)
    {
        isWordComplete = true;
    }
    else
    {
    char firstLetter = word.at(0);
    int indexNum;
    
    if( firstLetter == 'A')
        indexNum = 0;
    else if( firstLetter == 'B')
        indexNum = 1;
    else if( firstLetter == 'C')
        indexNum = 2;
    else if( firstLetter == 'D')
        indexNum = 3;
    else if( firstLetter == 'E')
        indexNum = 4;
    else if( firstLetter == 'F')
        indexNum = 5;
    else if( firstLetter == 'G')
        indexNum = 6;
    else if( firstLetter == 'H')
        indexNum = 7;
    else if( firstLetter == 'I')
        indexNum = 8;
    else if( firstLetter == 'J')
        indexNum = 9;
    else if( firstLetter == 'K')
        indexNum = 10;
    else if( firstLetter == 'L')
        indexNum = 11;
    else if( firstLetter == 'M')
        indexNum = 12;
    else if( firstLetter == 'N')
        indexNum = 13;
    else if( firstLetter == 'O')
        indexNum = 14;
    else if( firstLetter == 'P')
        indexNum = 15;
    else if( firstLetter == 'Q')
        indexNum = 16;
    else if( firstLetter == 'R')
        indexNum = 17;
    else if( firstLetter == 'S')
        indexNum = 18;
    else if( firstLetter == 'T')
        indexNum = 19;
    else if( firstLetter == 'U')
        indexNum = 20;
    else if( firstLetter == 'V')
        indexNum = 21;
    else if( firstLetter == 'W')
        indexNum = 22;
    else if( firstLetter == 'X')
        indexNum = 23;
    else if( firstLetter == 'Y')
        indexNum = 24;
    else if( firstLetter == 'Z')
        indexNum = 25;
    else
    {
        throw "There is no word!";
    }
     if (p_letters[indexNum] == 0)
     {
         string nxt = wordSoFar + word.substr(0,1);
         p_letters[indexNum] = new TrieElement(nxt);
     }
        p_letters[indexNum]->insertHelper(word.substr(1));
    }
}

string TrieElement :: searchHelper(const string& word)
{
  if (word.length() == 0)
  {
      if(isWordComplete == true)
      {
          return "FOUND";
      }
      else
      {
          return "PARTIAL";
      }
  }
  else
  {
      char firstLetter = word.at(0);
      int indexNum;
      
      if( firstLetter == 'A')
          indexNum = 0;
      else if( firstLetter == 'B')
          indexNum = 1;
      else if( firstLetter == 'C')
          indexNum = 2;
      else if( firstLetter == 'D')
          indexNum = 3;
      else if( firstLetter == 'E')
          indexNum = 4;
      else if( firstLetter == 'F')
          indexNum = 5;
      else if( firstLetter == 'G')
          indexNum = 6;
      else if( firstLetter == 'H')
          indexNum = 7;
      else if( firstLetter == 'I')
          indexNum = 8;
      else if( firstLetter == 'J')
          indexNum = 9;
      else if( firstLetter == 'K')
          indexNum = 10;
      else if( firstLetter == 'L')
          indexNum = 11;
      else if( firstLetter == 'M')
          indexNum = 12;
      else if( firstLetter == 'N')
          indexNum = 13;
      else if( firstLetter == 'O')
          indexNum = 14;
      else if( firstLetter == 'P')
          indexNum = 15;
      else if( firstLetter == 'Q')
          indexNum = 16;
      else if( firstLetter == 'R')
          indexNum = 17;
      else if( firstLetter == 'S')
          indexNum = 18;
      else if( firstLetter == 'T')
          indexNum = 19;
      else if( firstLetter == 'U')
          indexNum = 20;
      else if( firstLetter == 'V')
          indexNum = 21;
      else if( firstLetter == 'W')
          indexNum = 22;
      else if( firstLetter == 'X')
          indexNum = 23;
      else if( firstLetter == 'Y')
          indexNum = 24;
      else if( firstLetter == 'Z')
          indexNum = 25;
      else
      {
          throw "There is no word!";
      }
      if (p_letters[indexNum] == 0)
      {
          return "NOT FOUND";
      }
      else
      {
          return p_letters[indexNum]->searchHelper(word.substr(1));
      }
  }
}

void TrieElement :: printHelper()
{
    for (int i = 0; i < p_letters.size(); i++)
    {
        if(p_letters[i] != 0 && p_letters[i]->isWordComplete == true)
        {
        cout << p_letters[i]->wordSoFar << " ";
        p_letters[i]->printHelper();
        }
        else if(p_letters[i] != 0 && p_letters[i]->isWordComplete == false)
        {
            p_letters[i]->printHelper();
        }
    }
}

int TrieElement :: getNumElements()
{
    for (int i = 0; i < 26; i++)
    {
        if(p_letters[i] != NULL)
        {
            numElements++;
            p_letters[i]->getNumElements();
        }
    }
    return numElements;
}
