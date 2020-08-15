#include <iostream>

class A
{
public:
	A() {};
	A(int x_) { x = x_; }
	int x;
};

class B
{
public:
	B() : a(3), y(2) {}  // 'a' and 'y' MUST be initialized in an initializer list; it is an error not to do so

	//B()
	//{
	//	a = 3;
	//	y = 2;
	//}
private:
	A a;
	const int y;
//	int y;
};

int main()
{
	B b;

	getchar();
}
