//============================================================================
// Name        : Lab4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Stock.h"
#include "Portfolio.h"
using namespace std;

int main() {
	ifstream fin("portfolio.txt");
	if (fin.fail()){
		cout << "Input file opening failed.\n";
		exit(1);
		}

	Stock s1("LIN",4,20);

	Portfolio port1;
	port1.loadList(fin);			//Parse File into LinkedList
	port1.storeList(); 				//Store LinkedList in file
									//Problem: Last Line is ignored

	port1.printList();			//Print List From Beginning to End
	port1.printReverse();			//Print List From End to Beginning

	port1.insertNode(s1);		//Insert
	port1.storeList();
	port1.printList();
	port1.printReverse();

	port1.deleteNode();
	port1.storeList();
	port1.printList();
	port1.printReverse();
}
