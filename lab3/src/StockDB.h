/*
 * stockDB.h
 *
 *  Created on: Oct 4, 2017
 *      Author: Raul
 */

#ifndef STOCKDB_H_
#define STOCKDB_H_

#include "Stock.h"
#include "Node.h"
#include <iostream>

class StockDB{
	public:
	StockDB();
	StockDB(Node *h, Node *t, int c);
	void InsertNode(ifstream& ifs);
	Node* returnMiddleList();
	void splitList(StockDB& stockB, Node *middle);
	void printList();
	private:
	Node *head;
	Node *tail;
	int count;
};



#endif /* STOCKDB_H_ */
