//
// Created by Alix on 2/10/2022.
//
#pragma once

#include "QSInterface.h"

class QS : public QSInterface
{
protected:
	int valueCount, arrayCapacity;
	int* intArray = NULL;
public:
	QS();

	~QS() override;

	void sortAll() override;

	int medianOfThree(int leftIdx, int rightIdx) override;

	int partition(int leftIdx, int rightIdx, int pivotIndex) override;

	void quickSort(int left, int right); // TODO: does it need pivot?

	string getArray() const override;

	int getSize() const override;

	bool addToArray(int value) override;

	bool createArray(int capacity) override;

	void clear() override;

	template<typename T>
	static void Swap(T& val1, T& val2);
};