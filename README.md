# Data-Structure-Based-Projects
The following repository contains some of the projects I have personally completed that have an emphasis on implementing and applying various data structures in C++ programming.

## SafeArray 
The folder above contains the nessecary files to run and test a dynamically sizing array that I coded myself (commonly known as a vector). The SafeArray implements numerous different methods including: push_back(), pop_back(), at(), resize(), size(), and numerous others. The SafeArray demonstrates some of the cons of using a vector that aren't always apparent. The SafeArray is always taking up more memory than you actually realize. Also, keep in mind that whenever adding something to the front of the SafeArray, every element in the vector needs to be shifted and copied.

## Trie
The folder above contains the nessecary files to test and run the Trie data structure that I coded myself. A Trie is a variation of a Binary Search Tree, rather than using numbers, it compares strings. The structure of a Binary Search Tree and Trie is incredibly efficent for large amounts of data. It focuses on analyzing the data in chunks and dividing it, rather than linearly, allowing for the run time of the program to cut down from O(n) to O(logn).

## Boggle Game Solver
The folder above contains the files that are required to use and test a Boggle Game Solver I have implemented using my Trie data structure. The program takes a .txt file that contains every single word in the dictionary and loads it into a Trie. The program will then randomly generate a Boggle Board using various Boggle Dice. Finally, the program will navigate the board, using the Trie, it will check letter by letter for every partial and full word on the board. Notice that by using the Trie, despite the huge amount of work done by the program, the execution time is incredibly quick.

## Memory Manager
The folder above contains the files that are required to test and use a memory manager that I have implemented. The memory manager opearates using a variation of a linked-list. It has the ability to 'allocate' and 'deallocate' memory by marking a node as used/free. It also has the ability to clean itself up by coalescing left and right to combine multiple nodes of the same value tha are next to eachother. Understanding proper usage of the heap is essential to being able to properly implement and use various data structures in program.
