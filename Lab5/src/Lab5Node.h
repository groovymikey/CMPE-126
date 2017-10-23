/*
 * Node.h
 *
 *  Created on: Oct 4, 2017
 *      Author: Raul
 */

#ifndef LAB5NODE_H_
#define LAB5NODE_H_

#include "Lab5Stock.h"

class Node{
	public:
	Node();
	Node(Node* n, Stock& stockA);
	Node (Node &node);
	void setInfo(Stock &stockA);
	Stock getInfo();
	void setNext(Node *n);
	Node* getNext();
	private:
	Stock info;
	Node *next;

};



#endif /* LAB5NODE_H_ */
