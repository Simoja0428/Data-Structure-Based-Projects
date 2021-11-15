#include <iostream>
#include <ctime>
#include "SafeArray.hpp"
#include "SafeArrayException.hpp"

using namespace std;

void printSafeArray(const SafeArray < int >& s);
void simpleTest();
void constructorTest();
void atTest();
void pushPopTest();
void insertRemoveTest();
void randomTest(int cycles);

int main()
{
    srand(time(0));
    
    simpleTest();
    constructorTest();
    atTest();
    pushPopTest();
    insertRemoveTest();
    randomTest(1000000);

    return 0;
}
//--
void printSafeArray(const SafeArray < int >& s)
{
    //print the size
    cout<<"SafeArray Size: "<<s.size()<<endl;

    for(int i = 0;i < s.size();i++)
    {
        cout<<i<<": "<<s.at(i)<<endl;
    }
    cout<<endl;
}
//--
void simpleTest()
{
    //create some safe arrays, fill, and print
    SafeArray < int > s0;
    s0.push_back(10);
    s0.push_back(20);
    s0.push_back(30);
    s0.push_back(40);
    //print
    printSafeArray(s0);

    //SafeArray with an initial capacity of 100 but 0 elements
    SafeArray < int > s1(100);
    //add three elements to the back
    s1.push_back(10);
    s1.push_back(20);
    s1.push_back(30);
    //print
    printSafeArray(s1);
    
    //create a new array that is a copy
    SafeArray < int > s2(s1);
    s2.push_back(40);
    s2.push_back(50);
    s2.push_back(60);
    //print
    printSafeArray(s2);
}
//--
void constructorTest()
{
    //create an empty safe array and then fill it
    SafeArray < double > s0;
    if(s0.size() != 0)
    {
        cout<<"constructorTest Error 1"<<endl;
    }
    for(int i = 0;i < 20;i++)
    {
        s0.push_back(double(i * i));
    }
    if(s0.size() != 20)
    {
        cout<<"constructorTest Error 2"<<endl;
    }
    
    //create an empty safe array with capacity supplied in by the user and fill it
    SafeArray < double > s1(20);
    if(s1.size() != 0)
    {
        cout<<"constructorTest Error 3"<<endl;
    }
    for(int i = 0;i < 20;i++)
    {
        s1.push_back(double(i * i));
    }
    if(s1.size() != 20)
    {
        cout<<"constructorTest Error 4"<<endl;
    }
    
    //create a safe array by copying the elements of another
    SafeArray < double > s2(s1);
    if(s1.size() != 20)
    {
        cout<<"constructorTest Error 5"<<endl;
    }
    for(int i = 0;i < 20;i++)
    {
        s1.push_back(double(i * i));
    }
    if(s1.size() != 40)
    {
        cout<<"constructorTest Error 6"<<endl;
    }

    //attempt to create invalid sized safe arrays
    try
    {
        SafeArray < double > s1(0);
        cout<<"constructorTest Error 7"<<endl;
    } catch (SafeArrayException ex) {
        //do nothing
    }

    try
    {
        SafeArray < double > s1(-20);
        cout<<"constructorTest Error 8"<<endl;
    } catch (SafeArrayException ex) {
        //do nothing
    }
}
//--
void atTest()
{
    //create a safe array and fill it
    SafeArray < int > s0;
    for(int i = 0;i < 20;i++)
    {
        s0.push_back(i);
    }

    for(int i = 0;i < 20;i++)
    {
        if(s0[i] != i)
        {
            cout<<"atTest() Error 1"<<endl;
        }
    }
    
    //change some values
    s0[0] = 100;
    s0[10] = 100;
    s0[19] = 100;
    
    if(s0[0] != 100 || s0[10] != 100 || s0[19] != 100)
    {
        cout<<"atTest() Error 2"<<endl;
    }
    
    //attempt to access invalid elements
    try
    {
        s0[-1] = 0;
        cout<<"atTest() Error 3"<<endl;
    }
    catch (SafeArrayException ex) {
        //do nothing
    }

    try
    {
        s0[20] = 0;
        cout<<"atTest() Error 4"<<endl;
    }
    catch (SafeArrayException ex) {
        //do nothing
    }
    
    try
    {
        s0[200] = 0;
        cout<<"atTest() Error 5"<<endl;
    }
    catch (SafeArrayException ex) {
        //do nothing
    }
}
//--
void pushPopTest()
{
    //create a safe array and fill it
    SafeArray < int > s0;
    for(int i = 0;i < 100;i++)
    {
        s0.push_back(i);
    }
    //remove the elements
    for(int i = 99;i >= 0;i--)
    {
        if(s0.pop_back() != i)
        {
            cout<<"pushPopTest Error 1"<<endl;
        }
    }
    //refill it
    for(int i = 0;i < 100;i++)
    {
        s0.push_back(i);
    }
    //re-remove them
    for(int i = 99;i >= 0;i--)
    {
        if(s0.pop_back() != i)
        {
            cout<<"pushPopTest Error 2"<<endl;
        }
    }
    //add them back again
    for(int i = 0;i < 100;i++)
    {
        s0.push_back(i);
    }

    //create a new safe array
    SafeArray<int> s1;
    s1.push_back(100);
    s1.push_back(101);
    s1.push_back(102);
    //add the new one to the end of the first
    s0.push_back(s1);
    //verify the values
    for(int i = 102;i >= 0;i--)
    {
        if(s0.pop_back() != i)
        {
            cout<<"pushPopTest Error 3"<<endl;
        }
    }
}
//--
void insertRemoveTest()
{
    //insert at the beginning
    SafeArray < int > s0;
    for(int i = 0;i < 100;i++)
    {
        s0.push_back(i);
    }
    
    s0.insert(0, -1);
    
    if(s0[0] != -1 && s0[1] != 0)
    {
        cout<<"insertRemoveTest Error 1"<<endl;
    }

    //insert at the end
    SafeArray < int > s1;
    for(int i = 0;i < 100;i++)
    {
        s1.push_back(i);
    }
    
    s1.insert(99, -99);
    
    if(s1[99] != -99 && s1[100] != 99)
    {
        cout<<"insertRemoveTest Error 2"<<endl;
    }

    //verify both are the right size
    if(s0.size() != 101 || s1.size() != 101)
    {
        cout<<"insertRemoveTest Error 3"<<endl;
    }
    
    //remove from the beginning
    while(s0.size() > 0)
    {
        s0.remove(0);
    }
    if(s0.size() != 0)
    {
        cout<<"insertRemoveTest Error 4"<<endl;
    }

    //remove from the end
    for(int i = s1.size() - 1;i >= 0;i--)
    {
        s1.remove(i);
    }
    if(s1.size() != 0)
    {
        cout<<"insertRemoveTest Error 5"<<endl;
    }

    //insert one inside another
    for(int i = 0;i < 100;i++)
    {
        s0.push_back(i);
    }
    
    for(int i = 0;i < 100;i++)
    {
        s1.push_back(i);
    }
    
    s0.insert(0, s1);
    if(s0.size() != 200 || s1.size() != 100)
    {
        cout<<"insertRemoveTest Error 6"<<endl;
    }
    
    //remove ranges
    s0.removeRange(150, 199);
    if(s0.size() != 150)
    {
        cout<<"insertRemoveTest Error 7"<<endl;
    }
    s0.removeRange(100, 149);
    if(s0.size() != 100)
    {
        cout<<"insertRemoveTest Error 8"<<endl;
    }
    s0.removeRange(50, 99);
    if(s0.size() != 50)
    {
        cout<<"insertRemoveTest Error 9"<<endl;
    }
    s0.removeRange(0, 49);
    if(s0.size() != 0)
    {
        cout<<"insertRemoveTest Error 10"<<endl;
    }
}
//--
void randomTest(int cycles)
{
    SafeArray < int > s0;
    
    for(int i = 0;i < cycles;i++)
    {
        //pick an action at random
        int action = rand() % 5;
        //pick two positions in the safe array
        int pos1 = s0.size() > 0 ? rand() % s0.size() : 0;
        int pos2 = s0.size() > 0 ? rand() % s0.size() : 0;
        //pick what style of insert or remove to use
        int pushPopOrNot = rand() % 2 == 0;
        
        if(action == 0) //insert single
        {
            if(pushPopOrNot)
            {
                s0.push_back(0);
            }
            else
            {
                if(s0.size() > 0)
                {
                    s0.insert(pos1, 1);
                }
            }
        }
        else if(action == 1) //remove single
        {
            if(pushPopOrNot)
            {
                if(s0.size() > 0)
                {
                    s0.pop_back();
                }
            }
            else
            {
                if(s0.size() > 0)
                {
                    s0.remove(pos1);
                }
            }
        }
        else if(action == 2) //insert group
        {
            if(s0.size() > 0)
            {
                int numElements = rand() % 10;
                SafeArray<int> s1;
                for(int i = 0;i < numElements;i++)
                {
                    s1.push_back(i);
                }
                s0.insert(pos1, s1);
            }
        }
        else if(action == 3) //remove group
        {
            int minPos = min(pos1, pos2);
            int maxPos = max(pos1, pos2);
            
            if(s0.size() > 0 && minPos != maxPos)
            {
                s0.removeRange(minPos, maxPos);
            }
        }
        else //read and write random value
        {
            if(s0.size() > 0)
            {
                s0[pos1] = s0[pos2];
            }
        }
    }
}
