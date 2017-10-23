//============================================================================
// Name        : Lab5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Lab5complexDB.h"
#include "Lab5complex.h"
#include "Lab5StockDB.h"
using namespace std;

int main() {
	ifstream fin("complex.txt");
	if (fin.fail()){
		cout << "Input file opening failed.\n";
		exit(1);
	}

	ComplexDB ComArr;
	load(fin,ComArr);
	save(ComArr);
	cout <<"Largest Complex Number: " <<ComArr.recursiveLargest(0,ComArr.get_CurrSize()) <<endl;   //function defined in Lab5complexDB.cpp
	fin.close();

	StockDB s1;

	fin.open("stockfile.txt");
	if (fin.fail()){
		cout << "Input file opening failed.\n";
		exit(1);
	}
	s1.InsertNode(fin);
	Node* current = s1.getHead();
	cout <<"Reverse Print: " <<endl;
	s1.reverseRecursionPrint(current);  	//function defined in Lab5StockDB.cpp

}
