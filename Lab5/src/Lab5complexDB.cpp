#include "Lab5complexDB.h"
#include "Lab5complex.h"

ComplexDB::ComplexDB(){
	MaxSize = 20;
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
void load(ifstream &ifs, ComplexDB &arrA){
	ofstream fout("complexout.txt");
	if (fout.fail()){
		cout<<"Output file opening failed.\n";
		exit(1);
	}
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

		else if (ch == 'i'){
			img = real;
			real = 0;
			arrA.set_ComPtrElement(real,img,i);
			i++;
		}
//		else {
//			img = 0;
//			arrA.set_ComPtrElement(real,img,i);
//			i++;
//			cout << real << ss.peek() << endl;
//		}
		arrA.CurrSize++;

	//arrA.sort();
	}
	fout.close();
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

void save(ComplexDB &arrA){
	ofstream fout("complexout.txt");
	if (fout.fail()){
	cout<<"Output file opening failed.\n";
	exit(1);
	}
	for(int i = 0; i < arrA.CurrSize; i++){
			fout << arrA.ComPtr[i] <<endl;
	}
	fout.close();
}

Complex ComplexDB::recursiveLargest(int lower, int upper){
	Complex max;
	if(lower == upper){
		return ComPtr[lower];
	}
	else{
		max = recursiveLargest(lower+1,upper);
		if(ComPtr[lower] >= max){
			return ComPtr[lower];
		}
		else{
			return max;
		}

	}
}






