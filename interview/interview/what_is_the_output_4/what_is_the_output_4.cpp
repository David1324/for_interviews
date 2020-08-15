#include <iostream>
using namespace std;

class X
{
public:
	X(){ cout << "X() "; }
	~X(){ cout << "~X() "; }
};

class Y
{
public:
	Y(){ cout << "Y() "; }
	~Y(){ cout << "~Y() "; }
};

class Z : public X, public Y
{
public:
	Z(){ cout << "Z() "; }
	~Z(){ cout << "~Z() "; }
};

class A
{
public:
	A(){ cout << "A() "; }
	~A(){ cout << "~A() "; }
};

class B : public A
{
public:
	B(){ cout << "B() "; }
	~B(){ cout << "~B() "; }
};

class C : public B
{
public:
	C(){ cout << "C() "; }
	~C(){ cout << "~C() "; }
};

class F : public C, public Z
{
public:
	F(){ cout << "F() "; }
	~F(){ cout << "~F() "; }
};


int main()
{
	F f; 
	cout << endl;
	return 0;
}