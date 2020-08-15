// A program with virtual destructor
#include<iostream>

using namespace std;

class base {
public:
	base()
	{
		cout << "Constructing base \n";
	}
	virtual ~base()
	//~base()
	{
		cout << "Destructing base \n";
	}
};

class derived : public base {
public:
	derived()
	{
		cout << "Constructing derived \n";
	}
	~derived()
	{
		cout << "Destructing derived \n";
	}
};

int main(void)
{
	base* b = new derived();
	delete b;

	//base* b[2];
	//derived *d1 = new derived();
	//derived *d2 = new derived();
	//b[0] = d1;
	//b[1] = d2;
	//for (int i = 0; i < 2; i++)
	//{
	//	delete b[i];
	//}

	////derived *d = new derived();
	////base *b = d;
	////delete b;
	getchar();
	return 0;
}