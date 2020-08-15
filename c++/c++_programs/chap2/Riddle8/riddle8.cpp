#include <iostream>
using namespace std;

//class Polygon
//{
//protected:
//	double width, height;
//	Polygon(double width, double height)
//	{
//		this->width = width;
//		this->height = height;
//	}
//
//public:
//	virtual double area() { return 0; }
//	
//};

#define OPTION 1

class Polygon
{
protected:
	double width, height;

	Polygon(double width, double height)
	{
		this->width = width;
		this->height = height;
	}
public:
	//virtual double area() = 0;
	virtual double area() { return 0; };

};

class Triangle : public Polygon
{
public:
	Triangle(double width, double height) : Polygon(width, height) {}
	double area()
	{
		return 0.5*this->width * this->height;
	}
};

class Rectangle : public Polygon
{
public:
	Rectangle(double width, double height) : Polygon(width, height) {}
	double area()
	{
		return this->width * this->height;
	}
};

int main()
{
	Polygon* p = new Polygon(5,4); //will not work since the constructor is in protected mode (first option) or abstract class (second option)
	Polygon* t = new Triangle(5, 4);
	Polygon* r = new Rectangle(5, 4);
	//cout << "polygon area = " << p->area() << endl;
	cout << "Triangle area = " << t->area() << endl;
	cout << "Rectangle area = " << r->area() << endl;
	getchar();

}