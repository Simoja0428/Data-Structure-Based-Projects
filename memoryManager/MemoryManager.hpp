//
//  MemoryManager.cpp
//  memoryManager
//
//  Created by Jacob  Simonek on 12/1/20.
//
#pragma once

#include <iostream>

using namespace std;

class MemoryManager
{
public:
    MemoryManager(char* p_mem, int s); //Constructor for MemoryManager
    void* allocate(int size); //Sets aside space on the heap using nodes
    void deallocate(void* p_delete); //Frees up space on the heap
    void dump(); //Prints info about all blocks in system
    
private:
    char* p_memory; //Holds a char to represent number of bytes
    int size; //Adds together char values to hold a total size
    struct Node //Node structure
    {
        Node* p_next; //Pointer to next node
        Node* p_prev; //Pointer to prev node
        bool isFree; //Says whether the node is free or taken
        int sizeOfNode; //Holds the number of bytes of node
    };
    Node* p_head; //Node pointer for front directions
    Node* p_tail; //Node pointer for reverse directions
    Node* p_current; //Tracker for the nodes
    Node* largestFreeChunk(int size);//The largest free chunk in system
    bool canBeDeleted(void* p_delete); //Checks to see if inputted node can be deleted
    void coalesceRight(Node* p_NodeToBeDeleted); //Checks to combine nodes R
    void coalesceLeft(Node* p_NodeToBeDeleted); //Checks to combine nodes L
};
