/*
 * Portfolio.h
 *
 *  Created on: Oct 9, 2017
 *      Author: Raul
 */

#ifndef PORTFOLIO_H_
#define PORTFOLIO_H_

#include "Stock.h"
#include "Node.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

class Portfolio{
	public:
	Portfolio();
	Portfolio(Node* h, Node* t);
	void loadList(ifstream &ifs);
	void storeList();
	void printList();
	void printReverse();
	void insertNode(Stock &stock1);
	void deleteNode();
	Node* returnMiddleList();

	private:
	Node* head;
	Node* tail;
};



#endif /* PORTFOLIO_H_ */
