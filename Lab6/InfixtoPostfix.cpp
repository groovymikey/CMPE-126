#include "InfixtoPostfix.h"

void infixToPostfix::getInfix(string in){
	infix = in;
}

string infixToPostfix::showInfix(){
	return infix;
}

string infixToPostfix::showPostfix(){
	return postfix;
}

void infixToPostfix::convertToPostfix(){
	Stack stack;
	postfix = "";
	for(unsigned int i=0;i<infix.length();i++){
		if (isalpha(infix[i])){
			postfix += infix[i];
		}
		else{
			if(precedence(infix[i],stack.Top())){
				while(precedence(infix[i],stack.Top())){
					postfix += stack.Top();
					stack.pop();
				}
				stack.push(infix[i]);
			}
			else if(infix[i] == ')'){
				while(stack.Top() != '('){
					postfix += stack.Top();
					stack.pop();

				}
				stack.pop();
			}
			else{
				stack.push(infix[i]);
			}
		}
		//cout<<postfix<<"|"<<stack<<endl;
	}
	for(int i = 0; i<=stack.getTop(); i++){
		postfix += stack.Top();
		stack.pop();
	}
}

bool infixToPostfix::precedence(char a, char b){
	if(a == '-' && (b == '+' || b == '-' || b == '*' || b == '/')){
		return true;
	}
	else if(a == '+' && (b == '+' || b == '-' || b == '*' || b == '/')){
		return true;
	}
	else if(a == '*' && (b == '*' || b == '/')){
		return true;
	}
	else if(a == '/' && (b == '*' || b == '/')){
		return true;
	}
	else{
		return false;
	}

}

//			if(eq[i] == '-' && (list[top-1] == '+' || list[top-1] == '-' || list[top-1] == '*' || list[top-1] == '/')){
//				pop();
//				postfix += pop();
//				push(eq[i]);
//			}
//			else if(eq[i] == '+' && (list[top-1] == '+' || list[top-1] == '-' || list[top-1] == '*' || list[top-1] == '/' )){
//				pop();
//				postfix += pop();
//				push(eq[i]);
//			}
//			else if(eq[i] == '*' && (list[top-1] == '/' || list[top-1] == '*')){
//				pop();
//				postfix += pop();
//				push(eq[i]);
//			}
//			else if(eq[i] == '/' && (list[top-1] == '/' || list[top-1] == '*')){
//				pop();
//				postfix += pop();
//				push(eq[i]);
//			}
//			else if(eq[i] == ')'){
//				while(list[top-1] != '('){
//					postfix += this->pop();
//				}
//				pop();
//			}
//			else{
//				push(eq[i]);
//			}
//		}
//
//	}
//	for(int i = 0;i<top;i++){
//		postfix += this->pop();
//	}
//}



