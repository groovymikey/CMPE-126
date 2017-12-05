//============================================================================
// Name        : Lab7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Stack.h"
#include "Queue.h"
using namespace std;

int main() {
	Stack <char> stack;
	Queue queue;

	ifstream fin("palindrome.txt");
	if(fin.fail()){
		cout<<"File opening failed";
		exit(1);
	}

	string pal = "";
	string PalCheck;
	while(!fin.eof()){
		getline(fin,pal);										//Parsing Into Stack and Queue
		for (unsigned int i = 0; i < pal.length(); i++){
			if ( isalpha(pal[i]) ){
				stack.push(tolower(pal[i]));
				queue.addQueue(tolower(pal[i]));
			}
			//cout<<stack.Top()<<queue.getBackList()<<" ";
		}
		while(stack.getTop() != 0){
			//cout<<queue.getFrontList()<<" ";
			if(stack.Top() == queue.getFrontList()){
				PalCheck = "Yes";
				stack.pop();
				queue.deleteQueue();
			}
			else{
				PalCheck = "No";
				while(stack.getTop() != 0){
					stack.pop();
					queue.deleteQueue();
				}
			break;
			}

		}
		cout<<pal<<":"<<PalCheck<<endl;

		//cout<<queue.getFrontList()<<queue.getBackList()<<queue.getCount();
	}


}


