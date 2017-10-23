/*
 * stock.cpp
 *
 *  Created on: Oct 4, 2017
 *      Author: Raul
 */
#include "Stock.h"

Stock::Stock(){
	symbol = "N/A";
	cost = 0;
	shares = 0;
}

Stock::Stock(string a,int b ,int c){
	symbol = a;
	cost = b;
	shares = c;

}

Stock::Stock(const Stock& stockA){
	symbol = stockA.symbol;
	cost = stockA.cost;
	shares = stockA.shares;
}

void Stock::setSymbol(string a){
	symbol = a;
}

void Stock::setCost(int b){
	cost = b;
}

void Stock::setShares(int c){
	shares = c;
}

string Stock::getSymbol() const{
	return symbol;
}

int Stock::getCost() const{
	return cost;
}

int Stock::getShares() const{
	return shares;
}

Stock Stock::operator=(const Stock &stockA){
	this->symbol = stockA.symbol;
	this->cost = stockA.cost;
	this->shares = stockA.shares;
	return *this;
}

ostream& operator<<(ostream &ost, const Stock &stockA){
	ost << stockA.symbol <<" " << stockA.cost <<" " << stockA.shares <<endl;
	return ost;
}

