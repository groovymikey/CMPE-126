/*
 * Stack.cpp
 *
 *  Created on: Oct 31, 2017
 *      Author: Raul
 */
#include "Stack.h"

Stack::Stack(){
	top = 0;
	maxSize = 50;
	list = new char[maxSize];
}

Stack::Stack(Stack& st1){
	top = st1.top;
	maxSize = st1.maxSize;
	delete []list;
	list = new char[st1.maxSize];
	for(int i = 0; i < top; i++){
		list[i] = st1.list[i];
	}
}

Stack::~Stack(){
	delete []list;
	list = NULL;
}

void Stack::push(char a){
	if(top != maxSize){
		list[top] = a;
		top++;
	}
}

char Stack::pop(){
	char temp;
	if (top > 0){
		temp = list[top-1];
		top--;
		return temp;
	}
	else{
		cout <<"Stack is Empty"<<endl;
		return 0;
	}
}

int Stack::getTop(){
	return top;
}

int Stack::getMaxSize(){
	return maxSize;
}

char Stack::Top(){
	return list[top-1];
}

ostream& operator<<(ostream& ost,Stack& st1){
	for(int i=0; i<st1.getTop(); i++){
		cout<<st1.list[i];
	}
	return ost;
}

