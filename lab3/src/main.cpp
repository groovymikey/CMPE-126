//============================================================================
// Name        : lab3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Stock.h"
#include "StockDB.h"
using namespace std;

int main() {
	ifstream fin("stockfile.txt");
	if (fin.fail()){
			cout << "Input file opening failed.\n";
			exit(1);
		}

	StockDB s1,s2;				//Initialize StockDB Object head->NULL tail->NULL count = 0
	Node *middle;

	s1.InsertNode(fin);			//Populate Linked List
	cout <<"****Original List****" <<endl;
	s1.printList();
	cout <<endl;
	middle = s1.returnMiddleList(); //Returns Pointer To Middle of Linked List
	s1.splitList(s2,middle);
	cout <<"****LIST ONE****" <<endl;
	s1.printList();
	cout <<"****LIST TWO****" <<endl;
	s2.printList();
}

//OUTPUT OF PROGRAM

//****Original List****
//A1 1 1
//A2 2 2
//A3 3 3
//A4 4 4
//A5 5 5
//A6 6 6
//A7 7 7
//A8 8 8
//A9 9 9
//A10 10 10
//A11 11 11
//A12 12 12
//A13 13 13
//A14 14 14
//A15 15 15
//A16 16 16
//A17 17 17
//A18 18 18
//A19 19 19
//A20 20 20
//
//Middle at Position 10:
//A10 10 10

//Splitting List...
//****LIST ONE****
//A1 1 1
//A2 2 2
//A3 3 3
//A4 4 4
//A5 5 5
//A6 6 6
//A7 7 7
//A8 8 8
//A9 9 9
//A10 10 10
//****LIST TWO****
//A11 11 11
//A12 12 12
//A13 13 13
//A14 14 14
//A15 15 15
//A16 16 16
//A17 17 17
//A18 18 18
//A19 19 19
//A20 20 20
