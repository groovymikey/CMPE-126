
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "complex.h"
#include "complexDB.h"
using namespace std;

int main() {

	ifstream fin("126import.txt");
	if (fin.fail()){
		cout << "Input file opening failed.\n";
		exit(1);
	}

	ofstream fout("126complex.txt");
	if (fout.fail()){
		cout<<"Output file opening failed.\n";
		exit(1);
	}

	ComplexDB ComArr;
	load(fin,fout,ComArr);

//	int choice;
//
//	while(1){
//		cout << "Choose Function" << endl;
//		cout << "1.Add Complex Number" << endl << "2.Delete Complex Number" << endl;
//		cout << "3.List (Print To Console)" << endl << "4.Save (Print To File)" << endl <<"5.End Program" << endl;
//		cin >> choice;
//		cout << endl;
//		if (choice == 1){
//			add(ComArr);
//		}
//		else if (choice == 2){
//			Cdelete(ComArr);
//		}
//		else if (choice == 3){
//			list(ComArr);
//		}
//		else if (choice == 4){
//			save(fout,ComArr);
//		}
//		else if (choice == 5){
//			cout <<"END." <<endl;
//			exit(1);
//		}
//	}

	fin.close();
	fout.close();

}
//OUTPUT


//Choose Function
//1.Add Complex Number
//2.Delete Complex Number
//3.List (Print To Console)
//4.Save (Print To File)
//5.End Program
//1
//
//Input Complex Number in the form: a+bi
//4+4i
//Choose Function
//1.Add Complex Number
//2.Delete Complex Number
//3.List (Print To Console)
//4.Save (Print To File)
//5.End Program
//3
//
//1+i
//2+2i
//3.3+3.4i
//4+4i
//4.4-4.5i
//0+7i
//-5.5-5.6i
//0-8i
//
//Choose Function
//1.Add Complex Number
//2.Delete Complex Number
//3.List (Print To Console)
//4.Save (Print To File)
//5.End Program
//2
//
//Which Complex Number Would You Like To Delete? Enter Index of Number:
//8
//Index Invalid. Please Try Again
//Choose Function
//1.Add Complex Number
//2.Delete Complex Number
//3.List (Print To Console)
//4.Save (Print To File)
//5.End Program
//2
//
//Which Complex Number Would You Like To Delete? Enter Index of Number:
//5
//Choose Function
//1.Add Complex Number
//2.Delete Complex Number
//3.List (Print To Console)
//4.Save (Print To File)
//5.End Program
//4
//
//Choose Function
//1.Add Complex Number
//2.Delete Complex Number
//3.List (Print To Console)
//4.Save (Print To File)
//5.End Program
//5
//
//END.
