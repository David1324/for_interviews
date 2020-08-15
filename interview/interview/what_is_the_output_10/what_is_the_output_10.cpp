#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
	A(int n = 0) : m(n) {}

public:
	virtual int getVal() const {
		cout << "A::getVal() = ";
		return m;
	}
	virtual ~A() { }

protected:
	int m;
};

class B : public A
{
public:
	B(int n = 0) : A(n) {}

public:
	int getVal() const {
		cout << "B::getVal() = ";
		return m + 1;
	}
};

int main()
{
	const A a(1);
	const B b(3);
	const A *pA[2] = { &a, &b };
	cout << pA[0]->getVal() << endl;
	cout << pA[1]->getVal() << endl;

	vector<A> vA;
	vA.push_back(a);
	vA.push_back(b);
	vector<A>::const_iterator it = vA.begin();
	cout << it->getVal() << endl;
	cout << (it + 1)->getVal() << endl;

	return 0;
}