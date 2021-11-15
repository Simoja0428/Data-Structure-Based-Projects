//
//  SafeArray.hpp
//  BoggleAssignment
//
//  Created by Jacob  Simonek on 9/17/20.
//

#pragma once

#include <iostream>
#include "SafeArrayException.hpp"

using namespace std;

template < class T > //Needed above when creating a template class
class SafeArray
{
public:
    SafeArray(); //Default constructor for SafeArray
    SafeArray(int initCapacity); //Constructor  of certain size filled
    SafeArray(const SafeArray& other); //Constructor creates array copy of inputted array
    
    T& at(int pos) const; //Returns reference to element in Array
    T& operator[](int pos) const; //Alternative to the at()
    
    int size() const; //Returns the size of the Array
    void push_back(const T& elem); //Increase size of array and adds elements
    void push_back(SafeArray < T >& elems); //Increase size of array by adding array
    T pop_back(); //Returns value being deleted from end
    
    void insert(int position, const T& elem); //Inserts an element in SafeArray
    void insert(int position, SafeArray< T >& elems); //Inserts a SafeArray in array
    T remove(int position); //Removes an element
    void removeRange(int startIndex, int endIndex); //Removes multiple elements
    ~SafeArray();
    
private:
    T* p_arr; //Template pointer to be used to create arrays
    int capacity; //Keeps track of the size of the SafeArray
    int numElementsUsed; //Keeps track of how many spaces in SafeArray being used

    void resize(int newSize); //Resizes the array
};

/* ***************************************************************************************
 *****************************************************************************************
 Class (Above)
 Methods(Below)
 *****************************************************************************************
 ****************************************************************************************/

template <class T>

SafeArray< T > :: SafeArray() //Default constructor size 10 and empty
{
    capacity = 10; //Sets length of array to 10
    numElementsUsed = 0; //Sets number of elements used to 0 as array is empty
    p_arr = new T[10]; //Creates the array on the heap
}

template <class T>

SafeArray< T > :: SafeArray(int num) //Constructor is as large as user inputs
{
    if (num < 1)
    {
    SafeArrayException ex; //Creates exception object
    cout << "Your value needs to be larger than 0!" << endl;
    throw ex; //Throws exception to check
    }
    
    if (num >= 10) //Only runs if user input is greater than 10
    {
    capacity = num; //Sets length of array to user input
    numElementsUsed = 0; //Sets number of elements used to ful
    p_arr =  new T[num]; //Creates the array on the heap
    }
    else
    {
        capacity = 10; //Sets length of array to 10 if user input is too small
        numElementsUsed = 0; //Sets number of elements used to empty
        p_arr =  new T[10]; //Creates the array on the heap
    }
}

template <class T>

SafeArray< T > :: SafeArray(const SafeArray& other) //Constructor copies inputted array
{
    capacity = other.capacity; //Sets capacity to same as other array
    numElementsUsed = other.numElementsUsed; //Sets used elements as same in other array
    p_arr = new T[other.capacity]; //Creates same array as input
    
    for (int io = 0; io < numElementsUsed; io++) //Fills array with same values
    {
        p_arr[io] = other[io];
    }
    
}

template <class T>

T& SafeArray< T > :: at(int pos) const //Returns a reference to an element in array
{
    if (pos > numElementsUsed-1 || pos < 0)
    {
        SafeArrayException ex; //Creates exception object
        cout << "Your value is out of bounds!" << endl;
        throw ex; //Throws exception to check
    }
   
    T& returnValue = p_arr[pos]; //Sets value equal to position in array
    return returnValue;
}

template <class T>

T& SafeArray< T > :: operator[](int pos) const //Alternative to the at() method
{
    return at(pos); //Calls the at() method
}

template <class T>

int SafeArray< T > :: size() const //Returns the size of the array
{
    return numElementsUsed;
}

template <class T>

void SafeArray< T > :: resize(int newSize) //Resizes the array
{
    if ( newSize < 1)
    {
        SafeArrayException ex; //Creates exception object
        cout << "Your value needs to be larger than 0!" << endl;
        throw ex; //Throws exception to check
    }
    else if (newSize > 0 && newSize < 10)
    {
        newSize = 10; //Sets newSize to 10 if its smaller than that
    }
    T* newP_arr = new T[newSize]; //Creates a new array of size
    
    if ( newSize < capacity) //If new size is smaller than original
    {
    for (int i = 0; i < newSize; i++)
    {
        newP_arr[i] = p_arr[i];
    }
    }
    else if (newSize >= capacity) //If newSize  is bigger than original
    {
        for (int p = 0; p < newSize; p++)
        {
            newP_arr[p] = p_arr[p];
        }
    }
    delete[] p_arr;
    
    p_arr = newP_arr;
    capacity = newSize;
}

template <class T>

void SafeArray< T >:: push_back(const T& elem) //Adds a element to the end of SafeArray
{
    if (capacity == numElementsUsed)
    {
        capacity = capacity * 2; //Doubles size if array is full
    }
    
    T* newArray = new T[capacity];
    
    for (int i = 0; i < numElementsUsed; i++)
    {
        newArray[i] = p_arr[i];
    }

    newArray[numElementsUsed] = elem; //Sets last thing in array to elem
    delete[] p_arr;
    
    if( numElementsUsed < (capacity/2) && capacity > 20)
    {
        capacity = capacity/2;
    }
    p_arr = newArray;
    
    numElementsUsed++;
    capacity++;

}

template <class T>

void SafeArray< T >:: push_back(SafeArray<T> & elems) //Adds elements to array at end
{
    int num = elems.capacity; //Gets size of inputted array
    int num2 = elems.numElementsUsed;
    
    if (capacity == numElementsUsed)
    {
        capacity = capacity * 2;
    }
    else if ((capacity - numElementsUsed) < elems.capacity)
    {
        resize(num + capacity);
    }
    
    T* newArr = new T[capacity];
    
    int o = 0;
    
    for (int y = 0; y < numElementsUsed; y++)
    {
        newArr[y] = p_arr[y];
    }
    
    for (int i = numElementsUsed; i < (numElementsUsed + num2); i++) //Loops starting at end of existing
    {
        newArr[i] = elems[o];
        o++;
    }
    numElementsUsed = numElementsUsed + num2;
    
    delete[] p_arr;
    p_arr = newArr;
}

template <class T>

T SafeArray< T >:: pop_back() //Removes element from end returns it
{
    T* newArray = new T[capacity];
    
    if (numElementsUsed < 1)
    {
        SafeArrayException ex; //Creates exception object
        cout << "You can't pop back an empty array!" << endl;
        throw ex; //Throws exception to check
    }
    
    T holder = p_arr[numElementsUsed-1]; //Takes the value of the last element
    numElementsUsed--;
    
    for (int i = 0; i < numElementsUsed; i++)
    {
        newArray[i] = p_arr[i];
    }
    delete[] p_arr;
    
    if( numElementsUsed < (capacity/2) && capacity > 20)
    {
        capacity = capacity/2;
    }
    p_arr = newArray;
    
    return holder;
}

template <class T>

void SafeArray< T >:: insert(int position, const T& elem) //Inserts a new element
{
    if (capacity == numElementsUsed)
    {
        capacity = capacity * 2; //Doubles size if array is full
    }
    
    T* newArray = new T[capacity];
    
    if (position < 0 || position > numElementsUsed-1)
    {
        SafeArrayException ex; //Creates exception object
        cout << "Out of Bounds! You can't insert there!" << endl;
        throw ex; //Throws exception to check
    }
    
    
    int counter = 0;
    
    for (int i = 0; i < numElementsUsed+1; i++)
    {
        if ( i == position)
        {
            newArray[i] = elem; //Inserts element
        }
        else
        {
        newArray[i] = p_arr[counter];
        counter++;
        }
    }
    delete[] p_arr;
    p_arr = newArray;

    numElementsUsed++;
    
    if( numElementsUsed < (capacity/2) && capacity > 20)
    {
        capacity = capacity/2;
    }
     
}

template < class T >

void SafeArray< T >:: insert(int position, SafeArray <T>& elems)
{
    if (position < 0 || position > numElementsUsed-1)
    {
        SafeArrayException ex; //Creates exception object
        cout << "Out of Bounds! You can't insert there!" << endl;
        throw ex; //Throws exception to check
    }
    
    int num = elems.capacity; //Gets size of inputted array
    int num2 = elems.numElementsUsed;
    
    if (capacity == numElementsUsed)
    {
        capacity = capacity * 2;
    }
    else if ((capacity - numElementsUsed) < elems.numElementsUsed)
    {
        resize(num + capacity);
    }
    T* newArray = new T[capacity + num];

    int counter = 0;
    int p = 0;
    int temp = numElementsUsed;
    
    if ( num2 < 1)
    {
        for (int e = 0; e < numElementsUsed; e++)
        {
        newArray[e] = p_arr[e];
        }
    }
    else
    {
    for (int u = 0; u < (num2 + temp); u++ )
    {
        if ( u == position)
        {
            int h = u;
            for ( p = position; p < num2 + position; p++)
            {
            newArray[h] = elems[counter];
            counter++;
            numElementsUsed++;
            capacity++;
            h++;
            }
            u = p;
        }
        else
        {
            newArray[u] = p_arr[u-counter];
        }
    }
    }
    if( numElementsUsed < (capacity/2) && capacity > 20)
    {
        capacity = capacity/2;
    }
    delete[] p_arr;
    p_arr = newArray; //Sets array to temp array
}

template <class T>

T SafeArray< T >:: remove(int position) //Removes an element
{
    T* newArray = new T[capacity];
    
    if (position < 0 || position > numElementsUsed-1)
    {
        SafeArrayException ex; //Creates exception object
        cout << "Out of Bounds! You can't insert there!" << endl;
        throw ex; //Throws exception to check
    }
    
    T num = p_arr[position]; //Stores removed value
    
    int counter = 0;
    
    for (int i = 0; i < numElementsUsed; i++)
    {
        if ( i != position)
        {
            newArray[counter] = p_arr[i]; //Copies values
            counter++;
        }
    }
    numElementsUsed--;
    
    delete[] p_arr;

    p_arr = newArray;
    
    
    if( numElementsUsed < (capacity/2) && capacity > 20)
    {
        capacity = capacity/2;
    }
    return num;
}

template <class T>

void SafeArray< T >:: removeRange(int startIndex, int endIndex)  //Removes multiple
{
    if( numElementsUsed < (capacity/2) && capacity > 10)
    {
        capacity = capacity/2;
    }
    
    T* newArray = new T[capacity];
    
    if (startIndex < 0 || endIndex > numElementsUsed -1 || startIndex > endIndex )
    {
        SafeArrayException ex; //Creates exception object
        cout << "Out of Bounds! You can't do that" << endl;
        throw ex; //Throws exception to check
    }
    
    int counter = 0; //Used to keep track of values of i to not add
    
    for (int i = 0; i < numElementsUsed; i++)
    {
        if ( i < startIndex || i > endIndex)
        {
            newArray[counter] = p_arr[i];
            counter++;
        }
    }
    
   numElementsUsed = numElementsUsed - (endIndex-startIndex+1);
   delete[] p_arr;
    
    if (capacity < 10)
    {
        capacity = 10;
    }
    
    p_arr = newArray;

}

template <class T>

SafeArray< T > :: ~SafeArray() //Deletes p_arr
{
    delete[] p_arr;
}

