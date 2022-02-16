//
// Created by Alix on 2/10/2022.
//

#include "QS.h"

QS::QS()
{
	intArray = NULL;
	valueCount = 0;
}

QS::~QS()
{
	QS::clear();
}

void QS::sortAll()
{
	if(valueCount <= 1)
	{
		return;
	}

	quickSort(0, valueCount - 1); // TODO: double check if needs be -1
}

void QS::quickSort(int left, int right)
{

	int pivotIdx = medianOfThree(left, right);

	if (pivotIdx < 0)
	{
		return;
	}

	pivotIdx = partition(left, right, pivotIdx);

	if (pivotIdx < 0)
	{
		return;
	}

	quickSort(left, pivotIdx - 1);
	quickSort(pivotIdx + 1, right);
}


string QS::getArray() const
{
	if(	intArray == NULL ||
		valueCount < 1)
	{
		return "";
	}

	string arrayString = "";

	for (int i = 0; i < valueCount; i++)
	{
		arrayString += to_string(intArray[i]);

		if(i < valueCount - 1)
		{
			arrayString += ",";
		}
	}

	return arrayString;
}

int QS::getSize() const
{
	return valueCount;
}

bool QS::addToArray(int value)
{
	if (valueCount == arrayCapacity)
	{
		return false;
	}
	else
	{
		intArray[valueCount] = value;
		valueCount++;
	}
	return true;
}

bool QS::createArray(int capacity)
{
	// TODO: might need to be 0?
	if (capacity < 1)
	{
		return false;
	}

	if (intArray != nullptr)
	{
		clear();
	}

	arrayCapacity = capacity;

	intArray = new int[arrayCapacity];
	valueCount = 0;

	return true;
}

void QS::clear()
{
	delete[] intArray;
	intArray = NULL;
	valueCount = 0;
	arrayCapacity = 0;
}

int QS::partition(int leftIdx, int rightIdx, int pivotIndex)
{
	if (valueCount < 1)
	{
		return -1;
	}
	if (intArray == NULL ||
		valueCount <= 1 ||
		leftIdx < 0 || 
		rightIdx < 0 ||
		leftIdx >= arrayCapacity || 
		rightIdx > arrayCapacity ||
		leftIdx >= rightIdx ||
		pivotIndex < leftIdx || pivotIndex > rightIdx)
	{
		return -1;
	}
	Swap(intArray[leftIdx], intArray[pivotIndex]);

	int upIdx = leftIdx + 1;
	int downIdx = rightIdx;

	do
	{
		// out of bounds check && size value check
		while((upIdx < rightIdx) && (intArray[upIdx] <= intArray[leftIdx]))
		{
			upIdx++;
		}
		while((downIdx != leftIdx) && (intArray[downIdx] > intArray[leftIdx]))
		{
			downIdx--;
		}

		if (upIdx < downIdx)
		{
			Swap(intArray[upIdx], intArray[downIdx]);
		}

	} while (upIdx < downIdx);

	// put pivot value back in the center
	Swap(intArray[leftIdx], intArray[downIdx]);

	// return the pivot value
	return downIdx;
}

int QS::medianOfThree(int leftIdx, int rightIdx)
{
	bool isBorked = false;
	string errStr = "";
	if (valueCount == 0)
	{
		errStr = "empty array";
		isBorked = true;
	}
	if (leftIdx < 0 || rightIdx < 0)
	{
		errStr = "L or R idx is < 0";
		isBorked = true;
	}
	if (leftIdx >= rightIdx)
	{
		errStr = "leftIdx is not < rightIdx";
		isBorked = true;
	}
	if(leftIdx >= valueCount - 1 || rightIdx >= valueCount)
	{	
		errStr = "L or R idx is > valueCount";
		isBorked = true;
	}
	if (isBorked)
	{
		cerr << "IS BORKED! " << errStr << endl;
		cout << "leftIdx: " << leftIdx << "\t\trightIdx: " << rightIdx << endl;
		return -1;
	}

	// also catch if they're... out of bounds?? how do I know that??

	int medianIndex = (leftIdx + rightIdx) / 2;

	//printf("LeftV: %*d\tMidV: %*d\tRightV: %*d\n", 3, intArray[leftIdx], 3, intArray[medianIndex], 3, intArray[rightIdx]);

	if (intArray[leftIdx] > intArray[medianIndex])
	{
		Swap(intArray[leftIdx], intArray[medianIndex]);
	}
	if (intArray[medianIndex] > intArray[rightIdx])
	{
		Swap(intArray[medianIndex], intArray[rightIdx]);
	}
	if (intArray[leftIdx] > intArray[medianIndex])
	{
		Swap(intArray[leftIdx], intArray[medianIndex]);
	}

	return medianIndex;
}

template <typename T>
void QS::Swap(T& val1, T& val2)
{
	T temp = val1;
	val1 = val2;
	val2 = temp;
}
