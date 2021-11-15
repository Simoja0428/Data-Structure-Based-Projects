# Data-Structure-Based-Projects
The following repository contains some of the projects I have personally completed that have an emphasis on implementing and applying various data structures in C++ programming.

## SafeArray Project
The folder above contains the nessecary files to run and test a dynamically sizing array that I coded myself (commonly known as a vector). The SafeArray implements numerous different methods including: push_back(), pop_back(), at(), resize(), size(), and numerous others. The SafeArray demonstrates some of the cons of using a vector that aren't always apparent. The SafeArray is always taking up more memory than you actually realize. Also, keep in mind that whenever adding something to the front of the SafeArray, every element in the vector needs to be shifted and copied.

## Trie
The folder above contains the nessecary files to test and run the Trie data structure that I coded myself. A Trie is a variation of a Binary Search Tree, rather than using numbers, it compares strings. The structure of a Binary Search Tree and Trie is incredibly efficent for large amounts of data. It focuses on analyzing the data in chunks and dividing it, rather than linearly, allowing for the run time of the program to cut down from O(n) to O(logn).
