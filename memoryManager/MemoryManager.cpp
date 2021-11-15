//
//  MemoryManager.hpp
//  memoryManager
//
//  Created by Jacob  Simonek on 12/1/20.
//

#include "MemoryManager.hpp"

using namespace std;

MemoryManager :: MemoryManager(char* p_mem, int s) //Constructor for the memoryManager
{
    p_memory = p_mem;
    size = s;

    p_head = (Node*)p_memory; //Initializes all of the stuff for p_head;
    p_head->sizeOfNode = size - (2 * sizeof(Node));
    p_head->isFree = true;
    p_head->p_prev = 0;
    p_head->p_next = (Node*)(p_memory + size - sizeof(Node));

    p_tail = (Node*)(p_memory + size - sizeof(Node)); //Initializes all p_tail stuff
    p_tail->sizeOfNode = 0;
    p_tail->isFree = false;
    p_tail->p_prev = p_head;
    p_tail->p_next = 0;
    
    cout << "Inside MemoryManager constructor, the sizeof(Node) is: " << sizeof(Node)  << " sizeof(Node*) is: " << sizeof(Node*) << " size of a bool is: " << sizeof(bool) << endl;
        cout << endl; //Print statements asked for in output
}

void MemoryManager :: dump() //Dump function prety much prints out the memory info
{
    int i = 1; //Creates an int for the block counter
    p_current = p_head; //Sets tracker node to p_head
    
    while(p_current != p_tail)
    {
        if(p_current->isFree == true)//If the node the tracker is on is empty
        {
            cout << "\tBlock " << i << ": " << p_current->sizeOfNode << " bytes of free space." << endl;
        }
        else//If the node the tracker is on is used
        {
            cout << "\tBlock " << i << ": " << p_current->sizeOfNode << " bytes of used space." << endl;
        }
        p_current = p_current->p_next; //Advances the loop
        i++; //Adds to the block counter
    }
    cout << endl;  //For neatness
}

MemoryManager :: Node* MemoryManager :: largestFreeChunk(int size) //Looks for largest free chunk
{
    p_current = p_head; //Sets tracker to the head
    Node* largestNode = 0; //Creates a node pointer and makes it null
    int largestSize = -1;  //Starts the largest num very small
    
    while(p_current != p_tail)
    {
        if(p_current->sizeOfNode > largestSize && p_current->isFree == true)
        {
            largestNode = p_current; //Sets largest node to tracker
            largestSize = largestNode->sizeOfNode; //Updates largest size
        }
        p_current = p_current->p_next; //Advances the loop
    }
    
    if(largestNode->sizeOfNode < size) //If the size isn't big enough
    {
        largestNode = 0; //Sets the pointer to null then
    }
    
    return largestNode; //Returns the largest node
}

void* MemoryManager :: allocate(int size) //The allocate function
{
    Node* largeNode = largestFreeChunk(sizeof(Node) + size); //Finds largeest
    
    if(largeNode == 0) //If there is no space avaliable
    {
        return largeNode; //It returns null because the value of largeNode is
    }
    else //If theres space for the allocate
    {
        Node* p_newNode = (Node*)(((char*)largeNode) + size + sizeof(Node));
        
        p_newNode->isFree = true; //Sets new node space to empty
        p_newNode->sizeOfNode = largeNode->sizeOfNode - size - sizeof(Node);
        largeNode->isFree = false; //Sets large node space to full
        largeNode->sizeOfNode = size; //Updates large node size
        p_newNode->p_next = largeNode->p_next; //Updates new next pointer
        p_newNode->p_prev = largeNode; //Updates new prev poiner
        largeNode->p_next->p_prev = p_newNode; //Updates point in front large
        largeNode->p_next = p_newNode; //Updates the large next pointer
        
        return (void*)((char*)largeNode + sizeof(Node)); //Returns void*
    }
}

void MemoryManager :: coalesceRight(Node* p_nodeToBeDeleted) //Combine Right
{
    if(p_nodeToBeDeleted->p_next->isFree == true) //If there is free to right
    {
        p_nodeToBeDeleted->sizeOfNode = p_nodeToBeDeleted->p_next->sizeOfNode + p_nodeToBeDeleted->sizeOfNode + sizeof(Node); //Updates size
        p_nodeToBeDeleted->p_next = p_nodeToBeDeleted->p_next->p_next; //Updates the next pointer
        p_nodeToBeDeleted->p_next->p_prev = p_nodeToBeDeleted; //Updates the prev pointer
    }
}
    

void MemoryManager :: coalesceLeft(Node* p_nodeToBeDeleted) //Combine left
{
    if(p_nodeToBeDeleted != p_head && p_nodeToBeDeleted->p_prev->isFree == true) //If the node isn't the head and the left is free
    {
        p_nodeToBeDeleted->p_prev->sizeOfNode = p_nodeToBeDeleted->p_prev->sizeOfNode + p_nodeToBeDeleted->sizeOfNode + sizeof(Node); //Updates size
        p_nodeToBeDeleted->p_prev->p_next = p_nodeToBeDeleted->p_next; //Updates the pointer behind
        p_nodeToBeDeleted->p_next->p_prev = p_nodeToBeDeleted->p_prev;
        //Updates the pointer in front
    }
}

bool MemoryManager::canBeDeleted(void* p_delete) //Function does all the work
{
    p_current = p_head; //Sets the tracker to  be the head
    bool flag = false; //Flag will be used to track if it can be deleted
    
    while(p_current != p_tail)
    {
        if((char*)p_current + sizeof(Node) == p_delete) //Checks if they match
        {
            p_current->isFree = true; //Marks tracker as empty
            coalesceRight(p_current); //Checks to combine right
            coalesceLeft(p_current); //Checks to combine left
            flag = true; //Sets the flag to  true
            break; //Exits the loop
        }
        p_current = p_current->p_next; //Advances the loop
    }
    return flag; //Returns whether the function can be deleted or not
}

void MemoryManager::deallocate(void* p_delete) //Deallocate function
{
    canBeDeleted(p_delete); //CanBeDeleted() function does all of the work. Can be deleted works pretty much as a private deallocate.
}
