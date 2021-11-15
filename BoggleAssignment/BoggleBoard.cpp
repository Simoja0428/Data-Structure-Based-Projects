//
//  BoggleBoard.cpp
//  BoggleAssignment
//
//  Created by Jacob  Simonek on 11/27/20.
//

#include "BoggleBoard.hpp"

#include <iostream>
#include <string> // For the to_string() function

using namespace std;

BoggleBoard :: BoggleBoard(const string& dictionaryPath) : trie(dictionaryPath)
{
    string diceValues[25][6] = {
    { "N", "S", "C", "T", "E", "C" },
    { "A", "E", "A", "E", "E", "E" },
    { "H", "H", "L", "R", "O", "D" },
    { "O", "R", "W", "V", "G", "R" },
    { "S", "P", "R", "I", "Y", "Y" },
    { "S", "U", "E", "N", "S", "S" },
    { "M", "E", "A", "U", "E", "G" },
    { "S", "E", "P", "T", "I", "C" },
    { "D", "H", "H", "O", "W", "N" },
    { "L", "E", "P", "T", "I", "S" },
    { "S", "T", "L", "I", "E", "I" },
    { "A", "R", "S", "I", "Y", "F" },
    { "T", "E", "T", "I", "I", "I" },
    { "O", "T", "T", "T", "M", "E" },
    { "N", "M", "N", "E", "G", "A" },
    { "N", "N", "E", "N", "A", "D" },
    { "O", "U", "O", "T", "T", "O" },
    { "B", "Z", "J", "B", "X", "K" },
    { "A", "A", "F", "A", "S", "R" },
    { "T", "O", "O", "U", "W", "N" },
    { "O", "T", "H", "D", "D", "N" },
    { "R", "A", "A", "S", "F", "I" },
    { "H", "O", "D", "R", "L", "N" },
    { "E", "E", "E", "E", "A", "M" },
    { "He", "Qu", "Th", "In", "Er", "An" }
    };
    
    BoggleDie** allDice = new BoggleDie*[25];
    
    for (int i = 0; i < 25; i++)
    {
        allDice[i] = new BoggleDie(diceValues[i]);
    }
    for (int e = 0; e < 25; e++)
    {
        BoggleDie * dieTemp = allDice[e];
        int randomPosition = rand() % 25;
        allDice[e] = allDice[randomPosition];
        allDice[randomPosition] = dieTemp;
    }
    
    for (int q  = 0; q < 25; q++)
    {
        board[q/5][q%5] = allDice[q];
    }
}

BoggleBoard :: ~BoggleBoard()
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            delete board[row][col];
        }
    }
}

void BoggleBoard :: printBoard()
{
    for (int row = 0;  row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            if (board[row][col]->getRolledValue().length() == 1)
            {
                cout << board[row][col]->getRolledValue() << "  ";
            }
            else
            {
                cout << board[row][col]->getRolledValue() << " ";
            }
        }
        cout << endl;
    }
}

void BoggleBoard:: allCaps()
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            board[row][col]->allCaps();
        }
    }
}

void BoggleBoard :: solveHelper(const string& wordSoFar, int x, int y, SafeArray<string> prevDie)
{
   if ( x > 4 || x < 0 || y > 4 || y < 0)
   {
       return;
   }
    string x0 = to_string(x);
    string y0 = to_string(y);
    
    for (int i =  0; i < prevDie.size(); i++)
    {
        if (prevDie[i] == x0 + ":" + y0)
        {
            return;
        }
    }
    
    bool north = true;
    bool south = true;
    bool west = true;
    bool east = true;
    bool northWest = true;
    bool southWest = true;
    bool northEast = true;
    bool southEast = true;
    string newWord = wordSoFar + board[x][y]->getRolledValue();
    prevDie.push_back(x0 + ":" + y0);
    bool flag = true;
    
    if (north == true)
    {
        if (trie.search(newWord) == "FOUND")
        {
            solveHelper(newWord, x, y-1, prevDie);
        }
        else if (trie.search(newWord) == "PARTIAL")
        {
            solveHelper(newWord, x, y-1, prevDie);
        }
        else
        {
            north = false;
        }
    }
    if (south == true)
    {
        if (trie.search(newWord) == "FOUND")
        {
            solveHelper(newWord, x, y+1, prevDie);
        }
        else if (trie.search(newWord) == "PARTIAL")
        {
            solveHelper(newWord, x, y+1, prevDie);
        }
        else
        {
            south = false;
        }
    }
    if (east == true)
    {
        if (trie.search(newWord) == "FOUND")
        {
            solveHelper(newWord, x+1, y, prevDie);
        }
        else if (trie.search(newWord) == "PARTIAL")
        {
            solveHelper(newWord, x+1, y, prevDie);
        }
        else
        {
            east = false;
        }
    }
    if (west == true)
    {
        if (trie.search(newWord) == "FOUND")
        {
            solveHelper(newWord, x-1, y, prevDie);
        }
        else if (trie.search(newWord) == "PARTIAL")
        {
            solveHelper(newWord, x-1, y, prevDie);
        }
        else
        {
            west = false;
        }
    }
    if (northWest == true)
    {
        if (trie.search(newWord) == "FOUND")
        {
            solveHelper(newWord, x-1, y-1, prevDie);
        }
        else if (trie.search(newWord) == "PARTIAL" )
        {
            solveHelper(newWord, x-1, y-1, prevDie);
        }
        else
        {
            northWest = false;
        }
    }
    if (northEast == true)
    {
        if (trie.search(newWord) == "FOUND")
        {
            solveHelper(newWord, x+1, y-1, prevDie);
        }
        else if (trie.search(newWord) == "PARTIAL")
        {
            solveHelper(newWord, x+1, y-1, prevDie);
        }
        else
        {
            northEast = false;
        }
    }
    if (southWest == true)
    {
        if (trie.search(newWord) == "FOUND")
        {
            solveHelper(newWord, x-1, y+1, prevDie);
        }
        else if (trie.search(newWord) == "PARTIAL")
        {
            solveHelper(newWord, x-1, y+1, prevDie);
        }
        else
        {
            southWest = false;
        }
    }
    if (southEast == true)
    {
        if (trie.search(newWord) == "FOUND")
        {
            solveHelper(newWord, x+1, y+1, prevDie);
        }
        else if (trie.search(newWord) == "PARTIAL")
        {
            solveHelper(newWord, x+1, y+1, prevDie);
        }
        else
        {
            southEast = false;
        }
    }
    
    for (int r = 0; r < duplicateFilter.size(); r++)
    {
        if (newWord == duplicateFilter[r])
        {
            flag = false;
        }
    }
    if (newWord.length() >= 4 && trie.search(newWord) == "FOUND" && flag == true)
    {
        duplicateFilter.push_back(newWord);
        cout << newWord << " ";
    }
}

void BoggleBoard :: solve()
{
    for (int row1 = 0; row1 < 5; row1++)
    {
        for (int col1 = 0; col1 < 5; col1++)
        {
            board[row1][col1]->allCaps();
        }
    }
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            SafeArray<string> prevDie;
            solveHelper("", row, col, prevDie);
        }
    }
}

Trie BoggleBoard:: getTrie()
{
    return trie;
}
