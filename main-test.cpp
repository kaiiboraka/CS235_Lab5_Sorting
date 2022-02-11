#include "QS.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Always test your code on a problem you have worked out the answers to first
// Then when you have tested your code thoroughly, try the passoff code.
int main() {
	QS *qsptr = new QS;
	// Create an array with 44,75,23,43,55,12,64,77,33
	int testarray[]={44,75,23,43,55,12,64,77,33};
	qsptr->createArray(9);
	for(int i = 0; i < 9; i++) {
		qsptr->addToArray(testarray[i]);
	}
	cout << "Size "<<qsptr->getSize()<<endl;
	//Should be Size 9
	cout << "Array "<<qsptr->getArray()<<endl;
	//Should be Array 44,75,23,43,55,12,64,77,33
	int pivot = qsptr->medianOfThree(0, 8);
	cout << "Pivot "<<pivot<<endl;
	//Should be Pivot 4
	cout << "Array "<<qsptr->getArray()<<endl;
	//Should be Array 33,75,23,43,44,12,64,77,55
	int endingindex = qsptr->partition(0,8,pivot);
	cout << "EndingIndex "<<endingindex<<endl;
	//Shoud be EndingIndex 4
	cout << "Array "<<qsptr->getArray()<<endl;
  	//Should be Array 33,12,23,43,44,75,64,77,55
	int pivotleft = qsptr->medianOfThree(0, 3);
	cout << "Pivotleft "<<pivotleft<<endl;
	//Should be Pivot 1
	cout << "Array "<<qsptr->getArray()<<endl;
	//Should be Array 12,33,23,43,44,75,64,77,55
	int leftendingindex = qsptr->partition(0,3,pivotleft);
	cout << "LeftEndingIndex "<<leftendingindex<<endl;
	//Should be LeftEndingIndex 2
	cout << "Array "<<qsptr->getArray()<<endl;
  	//Should be Array 23,12,33,43,44,75,64,77,55
	int pivotleftleft = qsptr->medianOfThree(0, 1);
	cout << "Pivotleftleft "<<pivotleftleft<<endl;
	//Should be Pivotleftleft 0
	cout << "Array "<<qsptr->getArray()<<endl;
	//Should be Array 12,23,33,43,44,75,64,77,55
	int leftleftendingindex = qsptr->partition(0,1,pivotleft);
	cout << "LeftLeftEndingIndex "<<leftleftendingindex<<endl;
	//Shoud be EndingIndex 1
	cout << "Array "<<qsptr->getArray()<<endl;
  	//Should be Array 12,23,33,43,44,75,64,77,55
	return 0;
}
