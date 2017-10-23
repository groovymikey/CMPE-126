/*
 * Node.cpp
 *
 *  Created on: Oct 4, 2017
 *      Author: Raul
 */

#include "Lab5Node.h"
#include "Lab5Stock.h"

Node::Node(){
	next = NULL;
	info.setCost(0);
	info.setSymbol("N/A");
	info.setShares(0);
}

Node::Node(Node *n, Stock& stockA){
	next = n;
	info.setCost(stockA.getCost());
	info.setSymbol(stockA.getSymbol());
	info.setShares(stockA.getShares());
}

Node::Node(Node &node){
	next = node.next;
	info = node.info;
}

void Node::setInfo(Stock &stockA){
	info = stockA;
}

Stock Node::getInfo(){
	return info;
}

void Node::setNext(Node *n){
	next = n;
}

Node* Node::getNext(){
	return this->next;
}
