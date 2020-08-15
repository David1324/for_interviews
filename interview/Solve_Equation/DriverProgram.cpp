/**
* DriverProgram.cpp
*/
/****************************************
* @Author: Mark Alexander Edwards Jr.
*
* This program uses a utility class to solve
* complex equations represented by string
* expressions
****************************************/
#include <iostream>
#include <ctime>
#include <string>
#include "Numerics.cpp"
#include "EquationSolver.h"
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::string;
using namespace Numerics;
using namespace EquationHelper;
int main(){

	cout << ES::solve("5 + 3 * (8 - 4)") << endl << endl;
	cout << ES::solve("12 / (3 * 4) + 5") << endl << endl;
	while (true){
		cout << "Enter an equation you would \nlike to solve (enter 'exit' to quit): " << flush;
		try{
			string temp;
			getline(cin, temp);
			if (temp.compare("exit") == 0) exit(0);
			clock_t t1 = clock();
			cout << "Answer: " + ES::solve(temp, 4) << endl;
			clock_t t2 = clock();
			cout << "\nTime taken to calculate value: " <<
				(t2 - t1) << " Clock cycles" << endl;
		}
		catch (...){
			cout << "Invalid expression! Please try again!" << endl;
		}
	}
	cin.ignore();
	cin.get();
	return 0;
}