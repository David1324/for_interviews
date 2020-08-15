#include <iostream> 
using namespace std;

class Base
{
public:
	char* name;
	// virtual 
	void display() {
		cout << name << endl;
	}
};

class Derived : public Base
{
public:
	char* name;
	void display() {
		cout << name << ", " << Base::name << endl;
	}
};

int main()
{
	Derived d;
	d.name = "Derived Class";
	d.Base::name = "Base Class";

	Derived* dptr = &d;

	// standard conversion from Derived* to Base* 
	Base* bptr = dptr;

	// call Base::display() 
	// output: "Base Class"
	bptr->display();
	
	getchar();

	return 0;
}