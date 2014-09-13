#include <iostream>
#include <sstream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;


int sum(int size1, int inVar1, int* inArray)
{
	if(inVar1 == size1)
		return 0;
	else
		return inArray[inVar1] + sum(size1, inVar1+1, inArray);
}

int main (int argc, char * argv[])
{
	int counter = 0;
	int totalsum1 =0;
	int totalsum2 =0;
	int arraysize = 0;
	string currentstring;
	int* thepointer;
	string tempstr;

	double iterate = atof(argv[2]);
	clock_t start1, finish1, start2, finish2;
	double dur1, dur2;

	//argv[2] is going to be the number of iterations run for timing purposes

	std::ifstream myFile(argv[1]);

	if(arraysize==0)
	{
		getline(myFile, tempstr);
		arraysize = atoi(tempstr.c_str());
		counter = atoi(tempstr.c_str());
	}

	thepointer = new int[arraysize];

	for(int y = 0; y< arraysize; y++)
	{
		getline(myFile, currentstring);
		thepointer[y] = atoi(currentstring.c_str());
	}

	start1 = clock();
	for(int x =0; x<iterate; x++)
	{
		totalsum1=0;
		for(int z = 0; z<arraysize; z++)
		{
			totalsum1+=thepointer[z];
		}

	}
	finish1 = clock();

	dur1 = (double)(finish1 -start1);
	dur1/= (CLOCKS_PER_SEC * iterate);

	start2 = clock();
	for(int q =0; q<iterate; q++)
	{
		totalsum2 = sum(arraysize,0, thepointer);
	}
	finish2 = clock();

	dur2 = (double)(finish2 -start2);
	dur2/= (CLOCKS_PER_SEC * iterate);

	cout << totalsum2 << "||" << totalsum1;
	cout <<  "Elapsed time nonrecursive: " <<  dur1 << endl;
	cout << "Elapsed time recursive: " << dur2 << endl;
}

