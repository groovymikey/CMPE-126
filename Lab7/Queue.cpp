#include "Queue.h"

Queue::Queue(){
	qMaxSize = 100;
	qFront = 0;
	qBack = 0;
	list = new char[qMaxSize];
	count = 0;
}

Queue::~Queue(){
	delete [] list;
}

void Queue::addQueue(char elem){
	if(count == 0){
		list[qFront] = elem;
		count++;
	}
	else if(count > 0 && count != qMaxSize){
		qBack = ( qBack + 1 ) % qMaxSize;
		list[qBack] = elem;
		count++;
	}
}

void Queue::deleteQueue(){
	if(qBack == qFront){
		count--;
	}
	else if(count != 0){
		count--;
		qFront = ( qFront +1 ) % qMaxSize;

	}
	else{
		cout<<"Queue is Empty"<<endl;
	}
}

char Queue::getqBack(){
	return qBack;
}

char Queue::getqFront(){
	return qFront;
}

int Queue::getCount(){
	return count;
}

char Queue::getBackList(){
	return list[qBack];
}

char Queue::getFrontList(){
	return list[qFront];
}
