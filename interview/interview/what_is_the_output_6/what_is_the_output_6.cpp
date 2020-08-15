#include <iostream>

class A {
public:
	void f() {
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

class D : public C {
public:
	// No f()
};

int main()
{
	A *a = new A();
	B *b = new B();
	C *c = new C();
	D *d = new D();

	a->f();			// A::f()
	b->f();			// B::f()
	c->f();			// C::f()	
	d->f();			// C::f()

	((B *)c)->f();		// B::f()
	((A *)c)->f();		// A::f()
	((A *)b)->f();		// A::f()

	return 0;
}