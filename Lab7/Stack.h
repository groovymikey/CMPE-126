#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack{
	private:
		int top;
		int maxSize;
		T* list;
	public:
		Stack();
		Stack(Stack& st1);
		~Stack();

		int getTop();
		int getMaxSize();
		T Top();

		void push(T a);
		T pop();
};

template<class T>
Stack<T>::Stack(){
	top = 0;
	maxSize = 100;
	list = new T[maxSize];
}

template<class T>
Stack<T>::Stack(Stack& st1){
	top = st1.top;
	maxSize = st1.maxSize;
	delete []list;
	list = new T[st1.maxSize];
	for(int i = 0; i < top; i++){
		list[i] = st1.list[i];
	}
}

template<class T>
Stack<T>::~Stack(){
	delete []list;
	list = NULL;
}

template<class T>
void Stack<T>::push(T a){
	if(top != maxSize){
		list[top] = a;
		top++;
	}
}

template<class T>
T Stack<T>::pop(){
	T temp;
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

template<class T>
int Stack<T>::getTop(){
	return top;
}

template<class T>
int Stack<T>::getMaxSize(){
	return maxSize;
}

template<class T>
T Stack<T>::Top(){
	return list[top-1];
}
#endif /* STACK_H */
