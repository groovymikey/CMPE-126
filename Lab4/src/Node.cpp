/*
 * Node.cpp
 *
 *  Created on: Oct 4, 2017
 *      Author: Raul
 */

#include "Node.h"
#include "Stock.h"

Node::Node(){
	next = NULL;
	prev = NULL;
	info.setCost(0);
	info.setSymbol("N/A");
	info.setShares(0);
}

Node::Node(Node *n, Node* p, Stock& stockA){
	next = n;
	prev = p;
	info.setCost(stockA.getCost());
	info.setSymbol(stockA.getSymbol());
	info.setShares(stockA.getShares());
}

Node::Node(Node &node){
	next = node.next;
	prev = node.prev;
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

void Node::setPrev(Node *p){
	prev = p;
}

Node* Node::getPrev(){
	return this->prev;
}
