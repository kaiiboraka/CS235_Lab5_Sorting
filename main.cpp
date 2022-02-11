#include "QS.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int NUM_FILES = 5; // the total number of files to be read from

// the string array containing the file names
const string fileArray[NUM_FILES] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};

// This will take a string temp and a QS object and will execute an instruction from the string
// no return, but writes the results of the instruction into the ofs filestream
void parse_instruction(string temp, ofstream& ofs, QS* aptr);

// This function is a platform independent way of reading files of various line ending types.
// It's definiton is at the bottom of the file, don't worry if you don't understand it.
namespace ta
{
	istream& getline(istream& is, string& line);
}

int main()
{
	ifstream ifs; // create the stream to read in from the files
	ofstream ofs; // create the output stream to write to an output file
	string temp; // used to store the current instruction
	QS* qsptr = NULL;//the QS object

	for (int i = 0; i < NUM_FILES; i++)
	{
		ifs.open(fileArray[i]); // open the file to read from
		ofs.open("out_" + fileArray[i]); // open the file to write to
		qsptr = new QS();

		if (!ifs.is_open())
		{ // if the file did not open, there was no such file
			cout << "File " << i + 1 << " could not open, please check your lab setup" << endl;
		}
		else
		{
			cout << "Reading file" << i + 1 << ".txt..." << endl;
		}

		cout << "Beginning out_file" << i + 1 << ".txt write" << endl;
		while (ta::getline(ifs, temp))
		{ // while there are more instructions to get,
			parse_instruction(temp, ofs, qsptr); // parse the instructions using the QS
		}
		cout << "File write complete" << endl << endl;
		if (qsptr != NULL)
		{
			delete qsptr;
			qsptr = NULL;
		}
		ifs.close();
		ofs.close();
	}
	cout << "end" << endl; // indicate that the program has successfuly executed all instructions

	return 0;
}


void parse_instruction(string temp, ofstream& ofs, QS* aptr)
{
	string command, expression;
	stringstream ss(temp);

	QS newSorter;


	if (!(ss >> command))
	{ return; } // get command, but if string was empty, return
	if (command == "createArray")
	{
		int capacity;
		ss >> capacity;
		if (aptr->createArray(capacity))
		{
			ofs << temp << " True" << endl;
		}
		else
		{
			ofs << temp << " False" << endl;
		}
	}
	else if (command == "addToArray")
	{ // add an element to the array
		int valueToAdd;
		ss >> valueToAdd;

		cout << "val is " << valueToAdd << endl;

		if (aptr->addToArray(valueToAdd))
		{
			ofs << temp << " True" << endl;
		}
		else
		{
			ofs << temp << " False" << endl;
		}
	}
	else if (command == "getArray")
	{ // print the array
		ofs << temp << "\n " << aptr->getArray() << endl;
	}
	else if (command == "medianOfThree")
	{ // perform median of three between the given indices
		int l, r;
		ss >> l >> r;
		ofs << temp << " " << aptr->medianOfThree(l, r) << endl;
	}
	else if (command == "partition")
	{ // partition the elements in the given boundaries around the value at the given index
		int l, r, pivot;
		ss >> l >> r >> pivot;
		ofs << temp << " " << aptr->partition(l, r, pivot) << endl;
	}
	else if (command == "sortAll")
	{ // sort all elements in the array using quicksort
		aptr->sortAll();
		ofs << temp << endl;
	}
	else if (command == "getSize")
	{ // get the size of the array
		ofs << temp << " " << aptr->getSize() << endl;
	}
	else if (command == "clear")
	{ // clear the array
		aptr->clear();
		ofs << temp << endl;
	}
	else
	{ // invalid command, wrong input file format
		cout << "Command: \"" << command << "\"" << endl;
		cout << "Invalid command.  Do you have the correct input file?" << endl;
	}
}

// Version of getline which does not preserve end of line characters
namespace ta
{
	istream& getline(istream& in, string& line)
	{
		line.clear();

		istream::sentry guard(in, true); // Use a sentry to maintain the state of the stream
		streambuf* buffer = in.rdbuf();  // Use the stream's internal buffer directly to read characters
		int c = 0;

		while (true)
		{ // Continue to loop until a line break if found (or end of file)
			c = buffer->sbumpc(); // Read one character
			switch (c)
			{
				case '\n': // Unix style, return stream for further parsing
					return in;
				case '\r': // Dos style, check for the following '\n' and advance buffer if needed
					if (buffer->sgetc() == '\n')
					{ buffer->sbumpc(); }
					return in;
				case EOF:  // End of File, make sure that the stream gets flagged as empty
					in.setstate(ios::eofbit);
					return in;
				default:   // Non-linebreak character, go ahead and append the character to the line
					line.append(1, (char) c);
			}
		}
	}
}