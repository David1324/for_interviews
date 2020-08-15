#include <iostream>

class A {
public:
	//void f() {
	virtual void f() {
		std::cout << "A::f()" << std::endl;
	}
};

class B : public A {
public:
	void f() {
		std::cout << "B::f()" << std::endl;
	}
};

class C : public B {
public:
	void f() {
		std::cout << "C::f()" << std::endl;
	}
};

int main()
{
	A *a = new A();
	B *b = new B();
	C *c = new C();

	a->f();			// A::f()
	b->f();			// B::f()
	c->f();			// C::f()

	B* bc = (B*)c;
	std::cout << "bc coutput:  ";
	bc->f();

	((B *)c)->f();		// C::f() //since f is virtual function, the f() of the REAL class is called.
	((A *)c)->f();		// C::f()
	((A *)b)->f();		// B::f()

	getchar();

	return 0;
}