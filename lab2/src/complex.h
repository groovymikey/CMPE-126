/*
 * complex.h
 *
 *  Created on: Aug 30, 2017
 *      Author: Raul
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

class Complex{
	public:
		Complex();
		Complex(double realA, double imaginaryB);
		Complex(double real_part); //initialize the real part
		Complex(const Complex &numa);
		friend Complex operator+(const Complex &numa, const Complex &numb);
		Complex operator=(const Complex &numa);
		bool operator==(const Complex &numa);
		bool operator<(const Complex &numa);
		friend ostream& operator<<(ostream &ost, const Complex &numa);
		friend istream& operator>>(istream &ist, const Complex &numa);
		double get_real() const;
		double get_img() const;
		void set_real(double numa);
		void set_img(double numb);

	private:
		double real;
		double imaginary;


};
const Complex i(0,1);



#endif /* COMPLEX_H_ */
