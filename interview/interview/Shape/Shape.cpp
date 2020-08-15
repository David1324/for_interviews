#include <iostream>
using namespace std;

typedef int DIMENSION_TYPE;

class Shape
{
protected:
	DIMENSION_TYPE width;
	DIMENSION_TYPE height;

public:
	Shape(DIMENSION_TYPE a = 0, DIMENSION_TYPE b = 0)
	{
		width = a;
		height = b;
	}

	//virtual DIMENSION_TYPE area()
	//{
	//	cout << "Parent class area :" << endl;
	//	return 0;
	//}
	virtual DIMENSION_TYPE area() = 0; //pure virtual function
	
};

class Rectangle : public Shape
{
public:
	Rectangle(DIMENSION_TYPE a = 0, DIMENSION_TYPE b = 0) :Shape(a, b) { }
	int area()
	{
		cout << "Rectangle class area :" << endl;
		return (width * height);
	}
};

class Triangle : public Shape{
public:
	Triangle(DIMENSION_TYPE a = 0, DIMENSION_TYPE b = 0) :Shape(a, b) { }
	int area()
	{
		cout << "Triangle class area :" << endl;
		return (width * height / 2);
	}
};

// Main function for the program
int main()
{
	Shape *shape;
	Rectangle rec(10, 7);
	Triangle  tri(10, 5);

	DIMENSION_TYPE shapeArea;

	// store the address of Rectangle
	shape = &rec;
	// call rectangle area.
	shapeArea = shape->area();
	cout << "area of rectangle is " << shapeArea << endl;

	// store the address of Triangle
	shape = &tri;
	// call triangle area.
	shapeArea = shape->area();
	cout << "area of triangle is " << shapeArea << endl;
	getchar();
	return 0;
}