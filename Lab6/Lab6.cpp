//============================================================================
// Name        : Lab6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Stack.h"
#include "InfixtoPostfix.h"
using namespace std;

int main() {
	infixToPostfix itp;
	itp.getInfix("A+B-C");
	itp.convertToPostfix();
	cout<<itp.showPostfix()<<endl;

	itp.getInfix("(A+B)*C");
	itp.convertToPostfix();
	cout<<itp.showPostfix()<<endl;

	itp.getInfix("(A+B)*(C-D)");
	itp.convertToPostfix();
	cout<<itp.showPostfix()<<endl;

	itp.getInfix("A+((B+C)*(E-F)-G)/(H-I)");
	itp.convertToPostfix();
	cout<<itp.showPostfix()<<endl;

	itp.getInfix("A+B*(C+D)-E/F*G+H");
	itp.convertToPostfix();
	cout<<itp.showPostfix()<<endl;


}
