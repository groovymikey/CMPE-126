#ifndef COMPLEXDB_H_
#define COMPLEXDB_H_

#include <iostream>
#include "Lab5complex.h"
using namespace std;

class ComplexDB{
	public:
	ComplexDB();
	~ComplexDB();
	ComplexDB(const ComplexDB &arrA);
	ComplexDB operator=(const ComplexDB &arrA);
	int get_MaxSize() const;
	int get_CurrSize() const;
	void set_MaxSize(int a);
	void set_CurrSize(int a);
	void set_ComPtrElement(double real, double img, int elementNum);
	void increase_size(int size);
	void sort();

	friend void load(ifstream &ifs, ComplexDB &arrA);
	friend void add(ComplexDB &arrA);
	friend void Cdelete(ComplexDB &arrA);
	friend void list(ComplexDB &arrA);
	friend void save(ComplexDB &arrA);
	Complex recursiveLargest(int lower, int upper);

	private:
	int MaxSize;
	int CurrSize;
	Complex *ComPtr;

};



#endif /* COMPLEXDB_H_ */
