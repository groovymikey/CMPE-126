/*
 * complexDB.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: Raul
 */
#include "complexDB.h"
#include "complex.h"

ComplexDB::ComplexDB(){
	MaxSize = 10;
	CurrSize = 0;
	ComPtr = new Complex[MaxSize];

}

ComplexDB::~ComplexDB(){
	delete [] ComPtr;
	ComPtr = NULL;
}

ComplexDB::ComplexDB(const ComplexDB &arrA){
	this->MaxSize = arrA.MaxSize;
	this->CurrSize = arrA.CurrSize;
	ComPtr = new Complex[MaxSize];
	for (int i = 0; i < MaxSize; i++){
		this->ComPtr[i] == arrA.ComPtr[i];
	}
}

ComplexDB ComplexDB::operator =(const ComplexDB &arrA){
	if (this != &arrA){
		delete [] ComPtr;
		this->MaxSize = arrA.MaxSize;
		this->CurrSize = arrA.CurrSize;

		ComPtr = new Complex[MaxSize];
		for (int i = 0; i < MaxSize; i++){
			this->ComPtr[i] == arrA.ComPtr[i];
		}

	}
	return *this;

}



int ComplexDB::get_MaxSize() const{
	return MaxSize;
}

int ComplexDB::get_CurrSize() const{
	return CurrSize;
}

void ComplexDB::set_MaxSize(int a){
	MaxSize = a;
}

void ComplexDB::set_CurrSize(int a){
	CurrSize = a;
}

void ComplexDB::set_ComPtrElement(double real, double img, int elementNum){
	ComPtr[elementNum].set_real(real);
	ComPtr[elementNum].set_img(img);
}

void ComplexDB::increase_size(int size){
	MaxSize = size;
	Complex* temp = new Complex[MaxSize];

	for(int i = 0; i < CurrSize; i++){
		temp[i] = ComPtr[i];
	}

	delete [] ComPtr;
}

void ComplexDB::sort(){
    Complex temp;
	for(int outer = CurrSize-1;outer > 0;outer--){
     for(int i=0;i<outer;i++){
         if(ComPtr[outer] < ComPtr[i]){
             temp = ComPtr[outer];
             ComPtr[outer] = ComPtr[i];
             ComPtr[i] = temp;
         }
     }
	}
}
void load(ifstream &ifs, ofstream &ofs, ComplexDB &arrA){
	stringstream ss;
	string line;
	char ch;
	int i = 0;
	double real,img;
	while (!ifs.eof()){
		getline(ifs,line);
		ss.str(line);
		ss >> real;
		ch = ss.peek();
		if ((ch == '+') || (ch == '-')){
			ss >> ch >> img;
			if (ch == '-'){
				img = -1*img;
			}
			arrA.set_ComPtrElement(real,img,i);
			i++;
		}
//		else if ((ch != '+') || (ch != '-') || (ch != 'i')){   //This was to handle the -6 but it would set the numbers after to 0
//			img = 0;											//I also tried if(!ss.eof()), but it did not work
																//fin.get(ch); cout<<(int)ch;
//			arrA.set_ComPtrElement(real,img,i);
//			i++;
//		}
		else if (ch == 'i'){
			img = real;
			real = 0;
			arrA.set_ComPtrElement(real,img,i);
			i++;
		}
		arrA.CurrSize++;
	}
	arrA.sort();
}

void add(ComplexDB &arrA){
	cout << "Input Complex Number in the form: a+bi" << endl;
	int real,imaginary;
	cin >> real >> imaginary;
	cin.get();
	Complex c1(real,imaginary);

	arrA.CurrSize++;
	if (arrA.CurrSize + 1 >= arrA.MaxSize){
			arrA.MaxSize++;
			arrA.increase_size(arrA.MaxSize);
	}
	arrA.ComPtr[arrA.CurrSize-1] = c1;
	arrA.sort();
}

void Cdelete(ComplexDB &arrA){
	cout << "Which Complex Number Would You Like To Delete? Enter Index of Number:" << endl;
	int index;
	cin >> index;
	if ((arrA.CurrSize == 0) || (index < 0) || (index >= arrA.CurrSize)){
		cout <<"Index Invalid. Please Try Again" <<endl;
	}
	else{
		for (int i = index; i < arrA.CurrSize; i++){
			arrA.ComPtr[i] = arrA.ComPtr[i+1];
		}
		arrA.CurrSize--;
	}
}

void list(ComplexDB &arrA){
	for(int i = 0; i < arrA.CurrSize; i++){
		cout << arrA.ComPtr[i] <<endl;
	}
	cout <<endl;
}

void save(ofstream &ofs, ComplexDB &arrA){
	for(int i = 0; i < arrA.CurrSize; i++){
			ofs << arrA.ComPtr[i] <<endl;
		}
}




