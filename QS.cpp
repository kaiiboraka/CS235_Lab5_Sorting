//
// Created by Alix on 2/10/2022.
//

#include "QS.h"

QS::QS()
{
	intArray = new int[15];
	valueCount = 0;
}

QS::~QS()
{
	QS::clear();
}

void QS::sortAll()
{
}

string QS::getArray() const
{
	if(	intArray   == nullptr ||
		valueCount == 0)
	{
		return "";
	}

	string arrayString;

	for (int i = 0; i < arrayCapacity; i++)
	{
		arrayString += to_string(intArray[i]);
		if(i < arrayCapacity - 1)
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
	// TODO: POTENTIAL ERROR
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
}

int QS::partition(int leftIdx, int rightIdx, int pivotIndex)
{
	if (valueCount < 1)
	{
		return -1;
	}
	if (intArray == nullptr ||
		QS::getSize() <= 1 ||
		leftIdx < 0 || 
		rightIdx < 0 ||
		leftIdx >= arrayCapacity || 
		rightIdx > arrayCapacity ||
		leftIdx >= rightIdx ||
		pivotIndex < leftIdx || pivotIndex > rightIdx)
	{
		return -1;
	}

	//pivotIndex = medianOfThree(leftIdx, rightIdx);
	Swap(intArray[leftIdx], intArray[pivotIndex]);

	int upIdx = leftIdx + 1;
	int downIdx = rightIdx - 1;

	for (int i = 0; i < valueCount; i++)
	{
		cout << intArray[i] << " ";
	}
	cout << endl;

	do
	{
		while (intArray[upIdx] <= intArray[leftIdx])
		{
			upIdx++;
			// if(upIdx >= rightIdx - 1) break;
		}
		while (intArray[downIdx] >= intArray[leftIdx])
		{
			downIdx--;
			// if(downIdx <= leftIdx + 1) break;
		}

		if (intArray[upIdx] < intArray[downIdx])
		{
			Swap(intArray[upIdx], intArray[downIdx]);
		}

	} while (upIdx <= downIdx);

	// put pivot value back in the center
	Swap(intArray[leftIdx], intArray[downIdx]);

	// return the pivot value
	return intArray[downIdx];
}

int QS::medianOfThree(int leftIdx, int rightIdx)
{
	if (
		leftIdx >= rightIdx ||
		leftIdx < 0 || rightIdx < 0 ||
		rightIdx > arrayCapacity)
	{
		return -1;
	}
	// also catch if they're... out of bounds?? how do I know that??

	int medianIndex = (leftIdx + rightIdx) / 2;

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
void QS::Swap(T val1, T val2)
{
	T temp = val1;
	val1 = val2;
	val2 = temp;
}
