/*
 * InfixtoPostfix.h
 *
 *  Created on: Nov 1, 2017
 *      Author: Raul
 */

#ifndef INFIXTOPOSTFIX_H_
#define INFIXTOPOSTFIX_H_

#include "Stack.h"

class infixToPostfix{
	public:
	void getInfix(string in);
	string showInfix();
	string showPostfix();
	void convertToPostfix();
	bool precedence(char a, char b);
	private:
		string infix;
		string postfix;

};



#endif /* INFIXTOPOSTFIX_H_ */
