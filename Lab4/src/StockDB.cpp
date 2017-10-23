/*
 * StockDB.cpp
 *
 *  Created on: Oct 4, 2017
 *      Author: Raul
 */
#include "StockDB.h"

StockDB::StockDB(){
	head = NULL;
	tail = NULL;
	count = 0;
}

StockDB::StockDB(Node *h, Node *t, int c){
	head = h;
	tail = t;
	count = c;
}

void StockDB::InsertNode(ifstream& ifs){
	//cout <<"Inserting Node..." <<endl;
	int cost,shares;
	string symbol;
	Node *temp;
	Stock s1;
	while(!ifs.eof()){
		ifs >> symbol >> cost >> shares;
		s1.setSymbol(symbol);
		s1.setCost(cost);
		s1.setShares(shares);
		temp = new Node;
		temp->setInfo(s1);
		temp->setNext(NULL);

		if(head == NULL){
			head = temp;
			tail = temp;
		}
		else{
			tail->setNext(temp);
			tail = temp;
		}
		count++;
	}

	//cout << temp->getInfo();
}

Node* StockDB::returnMiddleList(){
	Node *slow, *fast;
	int index=1;
	slow = head;
	fast = head;
	while(fast != NULL){
		fast = fast->getNext();

		if(fast == NULL){
			break;
		}
		if(fast->getNext() == NULL){
			break;
		}
		slow = slow->getNext();
		fast = fast->getNext();
		index++;

	}
	cout <<"Middle at Position " <<index <<": " <<endl <<slow->getInfo() ;
	return slow;

}

void StockDB::splitList(StockDB &stockB, Node* middle){
	stockB.head = middle->getNext();
	stockB.tail = this->tail;
	this->tail = middle;
	this->tail->setNext(NULL);
	cout <<endl <<"Splitting List..." <<endl;


}

void StockDB::printList(){
	Node* temp = this->head;
	while(temp != NULL){
		cout << temp->getInfo();
		temp = temp->getNext();
	}
}
