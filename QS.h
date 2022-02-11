//
// Created by Alix on 2/10/2022.
//
#pragma once

#include "QSInterface.h"

class QS : public QSInterface
{
protected:
	int valueCount, arrayCapacity;
	int* intArray;
public:
	QS();

	~QS() override;

	void sortAll() override;

	int medianOfThree(int leftIdx, int rightIdx) override;

	int partition(int leftIdx, int rightIdx, int pivotIndex) override;

	string getArray() const override;

	int getSize() const override;

	bool addToArray(int value) override;

	bool createArray(int capacity) override;

	void clear() override;

	template<typename T>
	void BubbleSort(T arr[], int n);

	template<typename T>
	static void Swap(T* val1, T* val2);
};

/* 2 7 2 5 8 9 1 2 3
 *
 * PV = 5;
 *
 * small 4 2 3 1 2
 * equal 5
 * large 7 8 9
 *
 * pv 3
 *
 * small 2 1 2
 * e 3
 * l 4
 *
 * pv 1
 *
 * s
 * e 1
 * l 2 2
 *
 * s
 * e 2 2
 * l
 *
 * 1 2 2
 * 3
 * 4
 *
 */