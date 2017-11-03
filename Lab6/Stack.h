#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
using namespace std;

class Stack{
	private:
		int top;
		int maxSize;
		char* list;
	public:
		Stack();
		Stack(Stack& st1);
		~Stack();

		int getTop();
		int getMaxSize();
		char Top();

		void push(char a);
		char pop();
		friend ostream& operator<<(ostream& ost,Stack& st1);
};


#endif /* STACK_H */
