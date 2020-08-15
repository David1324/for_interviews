class Base {
public:
	void f();
	virtual void vf();
};

class Derived : public Base {
public:
	void f();
	void vf();
};

#include <iostream>
using namespace std;

void Base::f() {
	cout << "Base f()" << endl;
}

void Base::vf() {
	cout << "Base vf()" << endl;
}

void Derived::f() {
	cout << "Derived f()" << endl;
}

void Derived::vf() {
	cout << "Derived vf()" << endl;
}

int main()
{
	Base b1;
	Derived d1;
	b1.f();
	b1.vf();
	d1.f();
	d1.vf();

	Derived d2;  	// Derived object
	Base* bp = &d2; // Base pointer to Derived object
	bp->f();	// Base f()
	bp->vf();	// which vf()?

	getchar();

	return 0;
}