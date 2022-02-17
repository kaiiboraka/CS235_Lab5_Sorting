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

bool QS::createArray(int capacity)
{
	if (intArray != nullptr)
	{
		clear();
	}

	arrayCapacity = capacity;

	intArray = new int[arrayCapacity];
	valueCount = 0;

	return true;
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

void QS::sortAll()
{
	if (valueCount <= 1)
	{
		return;
	}

	quickSort(0, valueCount - 1);
}

void QS::quickSort(int left, int right)
{
	if (right - left < 1)
	{
		return;
	}
	if (right - left < 3)
	{
		medianOfThree(left, right);
		return;
	}

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

	// 3 5 8 10 12 14 56

	quickSort(left, pivotIdx - 1);
	quickSort(pivotIdx + 1, right);
}


int QS::medianOfThree(int leftIdx, int rightIdx)
{
	int medianIndex = (leftIdx + rightIdx) / 2;
	if (valueCount < 1)
	{
        return -1;
    }
	if (leftIdx < 0 || rightIdx > valueCount -1 || leftIdx >= rightIdx || 
	medianIndex < 0 || medianIndex < leftIdx || medianIndex > rightIdx)
	{
        return -1;
    }

	// 10 5 12 56 83 14 3
	// 10 56 3
	if (intArray[leftIdx] > intArray[medianIndex])
	{
		Swap(intArray[leftIdx], intArray[medianIndex]);
	}
	// 10 3 56
	if (intArray[medianIndex] > intArray[rightIdx])
	{
		Swap(intArray[medianIndex], intArray[rightIdx]);
	}
	// 3 10 56
	if (intArray[leftIdx] > intArray[medianIndex])
	{
		Swap(intArray[leftIdx], intArray[medianIndex]);
	}

	return medianIndex;
}

int QS::partition(int leftIdx, int rightIdx, int pivotIndex)
{
	if (valueCount < 1)
	{
		return -1;
	}
	if (leftIdx  < 0 ||
		rightIdx < 0 ||
		leftIdx  >= arrayCapacity ||
		rightIdx >= arrayCapacity ||
		leftIdx  >= rightIdx ||
		pivotIndex < leftIdx || 
		pivotIndex > rightIdx)
	{
		return -1;
	}

	// 3 5 12 10 8 14 56
	Swap(intArray[leftIdx], intArray[pivotIndex]);
	// 10 5 12 3 8 14 56
	// 0 - leftIdx val: 10


	int upIdx = leftIdx + 1;
	int downIdx = rightIdx;

	do
	{
		// out of bounds check && size value check
		while ((upIdx < rightIdx) && (intArray[upIdx] <= intArray[leftIdx]))
		{ // find a value larger than pivotValue...
			upIdx++;
		}//... and then stop "up". Then,
		// up = 2 - val 12 > 10
		while ((downIdx != leftIdx) && (intArray[downIdx] > intArray[leftIdx]))
		{// find a value smaller than pivotValue...
			downIdx--;
		}// and then stop "down".
		// down = 4 - val 8 < 10
		if (upIdx < downIdx)
		{
			Swap(intArray[upIdx], intArray[downIdx]);
		}// 10 5 8 3 12 14 56
		// down^ ^up
	}
	while (upIdx < downIdx);

	// put pivot value back in the center
	Swap(intArray[leftIdx], intArray[downIdx]);
	// 3 5 8 10 12 14 56

	// return the downIdx @ pivot
	return downIdx;
}

string QS::getArray() const
{
	if (intArray == NULL ||
		valueCount < 1)
	{
		return "";
	}

	string arrayString = "";

	for (int i = 0; i < valueCount; i++)
	{
		arrayString += to_string(intArray[i]);

		if (i < valueCount - 1)
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

void QS::clear()
{
	delete[] intArray;
	intArray = NULL;

	valueCount = 0;
	arrayCapacity = 0;
}

template<typename T>
void QS::Swap(T& val1, T& val2)
{
	T temp = val1;
	val1 = val2;
	val2 = temp;
}