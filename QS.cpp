//
// Created by Alix on 2/10/2022.
//

#include "QS.h"

QS::QS()
{
	valueCount = 0;
}

QS::~QS()
{

}

void QS::sortAll()
{

}

string QS::getArray() const
{
	string arrayString;

	for (int i = 0; i < arrayCapacity; i++)
	{
		arrayString += to_string(intArray[i]) + ",";
		if (i == arrayCapacity - 1)
		{
			break;
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
	if (capacity < 1)
	{ return false; }

	arrayCapacity = capacity;

	if (intArray != nullptr)
	{
		delete intArray;
	}

	intArray = new int[arrayCapacity];
	valueCount = 0;

	return true;
}

void QS::clear()
{
	delete intArray;
}

int QS::partition(int leftIdx, int rightIdx, int pivotIndex)
{
	pivotIndex = medianOfThree(leftIdx, rightIdx);


	return 0;
}

int QS::medianOfThree(int leftIdx, int rightIdx)
{
	if (leftIdx >= rightIdx ||
		leftIdx < 0 || rightIdx < 0)
	{
		return -1;
	}
	// also catch if they're... out of bounds?? how do I know that??


	const int MEDIAN_ARRAY_SIZE = 3;
	int medArr[MEDIAN_ARRAY_SIZE] = {leftIdx, (leftIdx + rightIdx) / 2, rightIdx};
	BubbleSort(medArr, MEDIAN_ARRAY_SIZE);

	return medArr[1];
}

template<typename T>
void QS::BubbleSort(T arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		// Last i elements are already in place
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

template<typename T>
void QS::Swap(T* val1, T* val2)
{
	T temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}
