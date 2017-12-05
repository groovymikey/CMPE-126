/*
 * Queue.h
 *
 *  Created on: Nov 15, 2017
 *      Author: Raul
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
using namespace std;

class Queue{
	private:
		int qFront;
		int qBack;
		int qMaxSize;
		char* list;
		int count;

	public:
		Queue();
		~Queue();
		void addQueue(char elem);
		void deleteQueue();
		char getqFront();
		char getqBack();
		int getCount();

		char getFrontList();
		char getBackList();

};



#endif /* QUEUE_H_ */
