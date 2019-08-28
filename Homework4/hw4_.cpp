#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib> //for exit()
#include <cassert>
using namespace std;

const int MAX_SIZE = 100;


//This program read files and sorting u
//I leaned some C++ grammar from CSDN.net and C++ Primer Plus
int readfile(int inputArray[], ifstream& instream);
/*input the files*/

int sort(int inputArray1[], int inputArray1_size,
	int inputArray2[], int inputArray2_size, int outputArray[]);
/*sort the numberof two files*/

void writefile(int outputArray[], int outputArray_size);
/*output the result in the file*/

int main()
{
	char str1[50], str2[50];
	ifstream inSteaml;
	int iArray1[MAX_SIZE];
	int iArray1_size;
	int iArray2[MAX_SIZE];
	int iArray2_size;
	int outArray[MAX_SIZE];
	cout << "*** Welcome to Boyang Yu¡¯s sorting program *** " << endl;
	cout << "Enter the first input file name: ";
	cin >> str1;

	inSteaml.open(str1);

	if (inSteaml.fail()) {
		cout << "Input file opening failed." << endl;
		exit(1);
	}

	iArray1_size = readfile(iArray1, inSteaml);

	inSteaml.close();

	cout << "The list of " << iArray1_size 
		<< " numbers in file " << str1 << " is:" << endl;

	for (int i = 0; i < iArray1_size; i++) {
		cout << iArray1[i] << endl;
	}

	cout << endl << "Enter the second input file name: ";
	cin >> str2;

	inSteaml.open(str2);

	//test if file not find
	if (inSteaml.fail()) {
		cout << "Input file opening failed." << endl;
		exit(1);
	}

	iArray2_size = readfile(iArray2, inSteaml);

	cout << "The list of " << iArray2_size 
		<< " numbers in file " << str2 << " is:" << endl;

	for (int i = 0; i < iArray2_size; i++) {
		cout << iArray2[i] << endl;
	}

	int allSize = sort(iArray1, iArray1_size, iArray2, iArray2_size, outArray);

	cout << endl << "The sorted list of " << iArray1_size + iArray2_size << " numbers is: ";

	int oArray_size = iArray1_size + iArray2_size - 1;

	sort(outArray, outArray + (oArray_size + 1));

	writefile(outArray, oArray_size);

	for (int i = 0; i <= oArray_size; i++)
	{
		cout << outArray[i] << " ";
	}
	return 0;
}

int readfile(int inputArray[], ifstream& inStream)
{
	int index = 0;
	inStream >> inputArray[index];
		while (!inStream.eof()) {
			index++;
			inStream >> inputArray[index];
		}
	return index;
}

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[])
{
	for (int i = 0; i < inputArray1_size; i++)
	{
		outputArray[i] = inputArray1[i];
	}
	for (int i = 0; i < inputArray2_size; i++)
	{
		outputArray[i + inputArray1_size] = inputArray2[i];
	}
	return 0;
}

void writefile(int outputArray[], int outputArray_size)
{
	ofstream out;
	out.open("output.txt", ios::app);
	for (int i = 0; i < outputArray_size; i++) {
		out << outputArray[i] << endl;
	}

	out.close();
	return;
}
