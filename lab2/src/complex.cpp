/*
 * complex.cpp
 *
 *  Created on: Aug 30, 2017
 *      Author: Raul
 */
#include "complex.h"


#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

Complex::Complex(){
	real = 0;
	imaginary = 0;
}

Complex::Complex(double realA, double imaginaryB){
	real = realA;
	imaginary = imaginaryB;
}

Complex::Complex(double numa){
	real = numa;
	imaginary = 0;
}

Complex::Complex(const Complex &numa){
	this->real = numa.real;
	this->imaginary = numa.imaginary;
}

Complex operator+(const Complex &numa, const Complex &numb){
	Complex numc;
	numc.real = numa.real + numb.real;
	numc.imaginary = numa.imaginary + numb.imaginary;
	return numc;
}

Complex Complex::operator=(const Complex &numa){
	this->real = numa.real;
	this->imaginary = numa.imaginary;
	return *this;
}

bool Complex::operator ==(const Complex &numa){
	if ((this->real == numa.real) && (this->imaginary == numa.imaginary)){
		return true;
	}
	else{
		return false;
	}
}

bool Complex::operator <(const Complex &numa){
	return sqrt(pow(real,2)+pow(imaginary,2)) < sqrt(pow(numa.real,2)+pow(numa.imaginary,2));
}

ostream& operator<<(ostream& ost, const Complex &numa){
	if(numa.imaginary == 0){
		ost << numa.real;
	}
	else{
		if(abs(numa.imaginary) == 1){
			if(numa.imaginary < 0){
				ost << numa.real << "-" << "i";
			}
			else{
				ost << numa.real << "+" << "i";
			}
		}
		else{
			if(numa.imaginary < 0){
				ost << numa.real << "-" << abs(numa.imaginary) << "i";
			}
			else{
				ost << numa.real << "+" << numa.imaginary << "i";
			}
		}
	}


	return ost;
}

istream& operator>>(istream& ist, const Complex &numa){
	ist>> numa.real;
	ist.get();
	ist>> numa.imaginary;
	return ist;
}

double Complex::get_real() const{
	return real;
}

double Complex::get_img() const{
	return imaginary;
}

void Complex::set_real(double numa){
	real = numa;
}

void Complex::set_img(double numb){
	imaginary = numb;
}

