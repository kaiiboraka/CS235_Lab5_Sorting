# Quicksort Lab

## Briefing: 
In this lab, you will implement the quicksort algorithm described in the book. Although there are other ways of selecting the pivot value, you should follow the algorithm described in section 10.9 of the book.  You will need to run valgrind on your code to make sure you dont have memory leaks or other errors.  You will need to use a destructor as part of the lab, so you should become familiar with destructors.

## Purpose
The purpose of this lab is to implement quicksort.

## Background
Quicksort is a sorting algorithm developed by Tony Hoare that, on average, makes O(n log n) comparisons to sort n items. It is also known as partition-exchange sort. In the worst case, it makes O(n^2) comparisons, though this behavior is rare. Quicksort is typically faster in practice than other O(n log n) algorithms. Additionally, quicksort's sequential and localized memory references work well with a cache. Quicksort can be implemented as an in-place partitioning algorithm,

## Requirements
You will need the files from this git repository to complete the lab.

### File 1 - Array Tests (20 points)
* This deals with testing operations such as creating and adding to an array. 

### File 2 - Median of Three (20 points)
* It will test your implementation of the median of three function.

### File 3 - Partition (20 points)
* It will test your implementation of the partition function.

### File 4 - Comprehensive Tests & Edge Cases (15 points)
* It will test whether or not your medianOfThree() and partition() functions work on cases that commonly cause problems.

### File 5 - Sort All (25 points)
* It will test whether or not you are able to create your own recursive function using the medianOfThree() and partition() functions you already coded for the previous tests.

## Requirement Notes
* No predefined data structures may be used for this lab; you must use an array.
* You are required to write a separate '.h' and '.cpp' for every class you implement.

