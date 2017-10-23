/*
 * stockDB.h
 *
 *  Created on: Oct 4, 2017
 *      Author: Raul
 */

#ifndef LAB5STOCKDB_H_
#define LAB5STOCKDB_H_

#include "Lab5Stock.h"
#include "Lab5Node.h"
#include <iostream>

class StockDB{
	public:
	StockDB();
	StockDB(Node *h, Node *t, int c);
	Node* getHead();
	Node* getTail();
	void setHead(Node* h);
	void setTail(Node* t);

	void InsertNode(ifstream& ifs);
	Node* returnMiddleList();
	void splitList(StockDB& stockB, Node *middle);
	void printList();
	void reverseRecursionPrint(Node* current);

	private:
	Node *head;
	Node *tail;
	int count;
};



#endif /* LAB5STOCKDB_H_ */
