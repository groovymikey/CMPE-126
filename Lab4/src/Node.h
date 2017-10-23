/*
 * Node.h
 *
 *  Created on: Oct 4, 2017
 *      Author: Raul
 */

#ifndef NODE_H_
#define NODE_H_

#include "Stock.h"

class Node{
	public:
	Node();
	Node(Node* n, Node* p, Stock& stockA);
	Node (Node &node);
	void setInfo(Stock &stockA);
	Stock getInfo();
	void setNext(Node *n);
	Node* getNext();
	void setPrev(Node *p);
	Node* getPrev();
	private:
	Stock info;
	Node *next;
	Node *prev;

};



#endif /* NODE_H_ */
