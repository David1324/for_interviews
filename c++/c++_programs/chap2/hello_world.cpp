//
//  IntAverage - average 3 numbers using integer arithmetic.
//               First add the sum of each number divided by 3
//               and second divide the sum of the three
//               numbers by 3.
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#define NUM_OF_RECTANGLES	2

struct TRectangle

{
private:
	double Length;
    double Height;	
	string name;

public:

	//TRectangle(double Height=0.0, double Length=0.0)
	TRectangle(double L=0.0, double H=0.0) : Length(L), Height(H) {}

	void setHeight(double Height)
	{
		this->Height = Height;
	}

	void setLength(double Length)
	{
		this->Length = Length;
	}

	void setName(string name)
	{
		this->name = name;
	}

	double getHeight() const { return Height; }
	double getLenght() const { return Length; }
	string getName() const { return name; }

	TRectangle& operator=(const TRectangle& Rect);
	friend TRectangle operator+(const TRectangle& x, const TRectangle& y);
	TRectangle operator+(const double d);
};

#if 1
TRectangle& TRectangle::operator=(const TRectangle& Rect)
{
	Length = Rect.Length;
	Height = Rect.Height;

	//name = Rect.name;

	return *this;
}

TRectangle operator+(const TRectangle& x, const TRectangle& y)
{
	TRectangle temp;
	
#if 0
	temp.setLength(x.getLenght() + y.getLenght());
	temp.setHeight(x.getHeight() + y.getHeight());
	temp.setName(x.getName() + "+" + y.getName());
#else
    temp.Length = x.Length + y.Length;
    temp.Height = x.Height + y.Height;
	temp.name = x.name + "+" + y.name;
#endif
	return temp;
}


TRectangle TRectangle::operator+(const double d)
{
	TRectangle temp;

	temp.Length = Length + d;
	temp.Height = Height + d;

	return temp;
}

#endif

int main(int nNumberofArgs, char* pszArgs[])
{

    TRectangle r[NUM_OF_RECTANGLES];
	

	r[0].setLength(30);
	r[0].setHeight(20);
	r[0].setName("rec1");

	r[1].setLength(300);
	r[1].setHeight(200);
	r[1].setName("rec2");

	//TRectangle recAdd = r[0] + r[1];
	TRectangle recAdd = r[0] + 5;


	r[1] = r[0];
	

	for (int i=0 ; i<NUM_OF_RECTANGLES ; i++)
	{
		cout << "r[" << i << "].Length = " << r[i].getLenght() << endl;
		cout << "r[" << i << "].Height = " << r[i].getHeight() << endl;
		cout << "r[" << i << "].name = " << r[i].getName() << endl;
		cout << endl;
	}

	cout << "recAdd.Length = " << recAdd.getLenght() << endl;
	cout << "recAdd.Height = " << recAdd.getHeight() << endl;
	cout << "recAdd.name = " << recAdd.getName() << endl;
	cout << endl;

    // wait until user is ready before terminating program
    // to allow the user to see the program results
    system("PAUSE");
    return 0;
}
