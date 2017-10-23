/*
 * Portfolio.cpp
 *
 *  Created on: Oct 9, 2017
 *      Author: Raul
 */
#include "Portfolio.h"

Portfolio::Portfolio(){
	head = NULL;
	tail = NULL;
}

Portfolio::Portfolio(Node* h, Node* t){
	head = h;
	tail = t;
}

void Portfolio::loadList(ifstream &ifs){
	//cout <<"Inserting Node..." <<endl;
	int cost = 0,shares = 0;
	string symbol = "N/A";
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
		temp->setPrev(NULL);

		if(head == NULL){
			head = temp;
			tail = temp;
		}
		else{
			tail->setNext(temp);
			temp->setPrev(tail);
			tail = temp;
		}
	}
}

void Portfolio::storeList(){
	ofstream fout("portfolioOut.txt");
	if (fout.fail()){
		cout << "Output file opening failed.\n";
		exit(1);
	}
	Node* temp = this->head;
	while(temp != NULL){
		fout << temp->getInfo();
		temp = temp->getNext();
	}
}

void Portfolio::printList(){
	cout << "Print List Forward..." <<endl;
	Node* temp = this->head;
	while(temp != NULL){
		cout << temp->getInfo();
		temp = temp->getNext();
	}
	cout <<endl;
}

void Portfolio::printReverse(){
	cout <<"Print List Backwards..." <<endl;
	Node* temp = this->tail;
	while(temp != NULL){
		cout << temp->getInfo();
		temp = temp->getPrev();
	}
	cout <<endl;
}

void Portfolio::insertNode(Stock &stock1){
	cout << "Insert At:" <<endl <<"1.Beginning" <<endl <<"2.Middle" <<endl <<"3.End" <<endl;
	int choice;
	Node *temp, *middle;
	cin >> choice;
	if (head == NULL){
		temp = new Node;
		temp->setInfo(stock1);
		head = temp;
		tail = temp;
	}
	else if(choice == 1){
		temp = new Node;
		temp->setInfo(stock1);
		temp->setNext(head);
		head->setPrev(temp);
		head = temp;
	}
	else if(choice == 2){
		temp = new Node;
		temp->setInfo(stock1);
		middle = this->returnMiddleList();
		temp->setPrev(middle);
		temp->setNext(middle->getNext());
		middle->getNext()->setPrev(temp);
		middle->setNext(temp);
	}
	else if(choice == 3){
		cout << "End";
		temp = new Node;
		temp->setInfo(stock1);
		temp->setPrev(tail);
		tail->setNext(temp);
		tail = temp;
	}
	else{
		cout << "Wrong Key" <<endl;
	}
}

void Portfolio::deleteNode(){
	cout << "Delete At:" <<endl <<"1.Beginning" <<endl <<"2.Middle" <<endl <<"3.End" <<endl;
	int choice;
	Node *temp, *middle;
	cin >> choice;
		if (head == NULL){
			cout <<"List Is Empty" <<endl;
		}
		else if(head == tail){
			temp = head;
			head = NULL;
			tail = NULL;
			delete temp;
			cout << "List is now Empty" <<endl;
		}
		else if(choice == 1){
			temp = head;
			temp->getNext()->setPrev(NULL);
			head = temp->getNext();
			temp->setNext(NULL);
			delete temp;
		}
		else if(choice == 2){
			middle = this->returnMiddleList();
			middle->getNext()->setPrev(middle->getPrev());
			middle->getPrev()->setNext(middle->getNext());
			middle->setPrev(NULL);
			middle->setNext(NULL);
			delete middle;
		}
		else if(choice == 3){
			temp = tail;
			temp->getPrev()->setNext(NULL);
			tail = temp->getPrev();
			temp->setPrev(NULL);
			delete temp;
		}
		else{
			cout << "Wrong Key" <<endl;
		}
}

Node* Portfolio::returnMiddleList(){
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
		//cout <<"Middle at Position " <<index <<": " <<endl <<slow->getInfo() ;
		return slow;
}
