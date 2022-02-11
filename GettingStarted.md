# quicksort
In this tutorial we will help you to get started on the quicksort lab.  In this lab you will not be able to use a lot of the book code, so this tutorial will mostly show you examples of how to implement each step of the lab.  You should make sure that all of the code you submit is your own.

First download the lab files.  They are in this git repository.  Then create "QS.h" that inherits from "QSInterface.h" and "QS.cpp" that implements the functions.  Make sure that your code compiles.

Now you will start implementing the functions.  Lets start with 
```c++
	/*
	* Dynamically allocates an array with the given capacity.
	* If a previous array had been allocated, delete the previous array.
	* Returns false if the given capacity is non-positive, true otherwise.
	*
	* @param
	*		size of array
	* @return
	*		true if the array was created, false otherwise
	*/
        createArray(int capacity) = 0;
```
You will need to declare a class variable to point to the array you allocate with "new int[capacity]"

Now that you have an array, you can implement
```c++
	/*
	* Adds the given value to the end of the array starting at index 0.
	* For example, the first time addToArray is called,
	* the give value should be found at index 0.
	* 2nd time, value should be found at index 1.
	* 3rd, index 2, etc up to its max capacity.
	*
	* If the array is filled, do nothing.
	* returns true if a value was added, false otherwise.
	*/
	virtual bool addToArray(int value) = 0;
```
You will need to create a class variable to keep track of the current insert position and increment it after each insert.

Now finish the other easy functions
```c++
	/*
	* Produces a comma delimited string representation of the array. For example: if my array
	* looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
	* with no trailing comma.  The number of cells included equals the number of values added.
	* Do not include the entire array if the array has yet to be filled.
	*
	* Returns an empty string, if the array is NULL or empty.
	*
	* @return
	*		the string representation of the current array
	*/
	virtual string getArray() const = 0;

	/*
	* Returns the number of elements which have been added to the array.
	*/
	virtual int getSize() const = 0;
  	/*
	* Resets the array to an empty or NULL state.
	*/
	virtual void clear() = 0;
```
You should be able to create an array, add a bunch of numbers and use getArray to output the array.  Call these functions inside of test code that you write in main.cpp.

Now implement 
```c++
	/*
	* medianOfThree()
	*
	* The median of three pivot selection has two parts:
	*
	* 1) Calculates the middle index by averaging the given left and right indices:
	*
	* middle = (left + right)/2
	*
	* 2) Then bubble-sorts the values at the left, middle, and right indices.
	*
	* After this method is called, data[left] <= data[middle] <= data[right].
	* The middle index will be returned.
	*
	* Returns -1 if the array is empty, if either of the given integers
	* is out of bounds, or if the left index is not less than the right
	* index.
	*
	* @param left
	* 		the left boundary for the subarray from which to find a pivot
	* @param right
	* 		the right boundary for the subarray from which to find a pivot
	* @return
	*		the index of the pivot (middle index); -1 if provided with invalid input
	*/
	virtual int medianOfThree(int left, int right) = 0;
```
You will be calling this function before you partition your data, so make sure you have it right.  It should return the index of the pivot value.  You can perform the bubble sort on three elements by simple if statements.  For example, assume that you have the array
```
44,75,23,43,55,12,64,77,33
left = 0, right = 8
middle = (left+right)/2 = 4
now sort the values 44,55,33 to get 
33,75,23,43,44,12,64,77,55
and return the middle index 4
```
The lab mentions that you should follow the algorithm on page 611.
![book page](https://mjcleme.github.io/page611.png )
Now implement
```c++
	/*
	* Partitions a subarray around a pivot value selected according to
	* median-of-three pivot selection.  Because there are multiple ways to partition a list,
	* we will follow the algorithm on page 611 of the course text when testing this function.
	*
	* The values which are smaller than the pivot should be placed to the left
	* of the pivot; the values which are larger than the pivot should be placed
	* to the right of the pivot.
	*
	* Returns -1 if the array is null, if either of the given integers is out of
	* bounds, or if the first integer is not less than the second integer, or if the
	* pivot is not within the sub-array designated by left and right.
	*
	* @param left
	* 		the left boundary for the subarray to partition
	* @param right
	* 		the right boundary for the subarray to partition
	* @param pivotIndex
	* 		the index of the pivot in the subarray
	* @return
	*		the pivot's ending index after the partition completes; -1 if
	* 		provided with bad input
	*/
	virtual int partition(int left, int right, int pivotIndex) = 0;
```
So, given the data resulting from medianOfThree():
```
33,75,23,43,44,12,64,77,55
left = 0, right = 8, pivotIndex = 4
```
You can now call
```
pivotEnd = partition(0, 8, 4);
```

Now you just need to implement
```c++
	/*
	* sortAll()
	*
	* Sorts elements of the array.  After this function is called, every
	* element in the array is less than or equal its successor.
	*
	* Does nothing if the array is empty.
	*/
	virtual void sortAll() = 0;
```
You will need to write your own function for recursively calling `medianOfThree()` and `partition()`. `sortAll` should call this function with the appropriate starting parameters.

