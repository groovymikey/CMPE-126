/*
 * stock.h
 *
 *  Created on: Oct 4, 2017
 *      Author: Raul
 */

#ifndef LAB5STOCK_H_
#define LAB5STOCK_H_

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Stock{
	public:
	Stock();
	Stock(string a, int b , int c);
	Stock(const Stock& stockA);
	void setSymbol(string a);
	void setCost(int b);
	void setShares(int c);
	string getSymbol() const;
	int getCost() const;
	int getShares() const;
	Stock operator=(const Stock &stockA);
	friend ostream& operator<<(ostream &ost, const Stock& stockA);

	private:
	string symbol;
	int cost;
	int shares;
};



#endif /* LAB5STOCK_H_ */
