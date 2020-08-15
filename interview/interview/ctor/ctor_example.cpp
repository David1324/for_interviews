#include<iostream>
using namespace std;

class Test
{
	/* Class data members */
public:
	//if we remove const from the copy-constructor, there will be error in compilation.
	Test(const Test &t) { /* Copy data members from t*/ }
	Test() { /* Initialize data members */ }
};

Test fun()
{
	cout << "fun() Called\n";
	Test t;
	return t; 
	//returns by VALUE. therefore the compiler creates a temporary object that is copied to t2.
	//therefore, there's a call to copy constructor here.
	//if a compiler creates a TEMPORARY object, it MUST be CONST. 
	//it's reasonable since it's temporary, you want to ensure that t (the output of fun) is really the object put in t2 and nothing else.
	//without the const, you can't be sure about that so you can't gurantee that t2 will indeed contain the output of fun().
}

int main()
{
	Test t1;
	Test t2 = fun();
	getchar();
	return 0;
}