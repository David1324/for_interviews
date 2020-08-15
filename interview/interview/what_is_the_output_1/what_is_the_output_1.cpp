#include <iostream>
using namespace std;

class A
{
public:
	A(int n = 1) : ia(n)
	{
		cout << "A() ia = " << ia << endl;
	}
	~A()
	{
		cout << "~A() ia = " << ia << endl;
	}

protected:
	int ia;
};

//notice that constructor of a2 is called before a1 since the order is by the definitions in the private members and not by the order in the initialization list
class B : public A
{
public:
	B(int n) : a1(ia + 10), a2(n), A(2)
	{
		cout << "B() ia = " << ia << endl;
	}
	~B()
	{
		cout << "~B() ia = " << ia-- << endl;
	}

private:
	A a2;
	A a1;
};

int main()
{
	{ B b(20); }

	return 0;
}