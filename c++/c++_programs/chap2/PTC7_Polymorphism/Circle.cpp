#include "Shape.h"
#include "Circle.h"
#include <iostream>

using std::cout;
using std::endl;


//Initialization Lists : Summary
//Before the body of the constructor is run, all of the constructors for its parent class and then for its fields are invoked.By default, the no - argument constructors are invoked.Initialization lists allow you to choose which constructor is called and what arguments that constructor receives.
//If you have a reference or a const field, or if one of the classes used does not have a default constructor, you must use an initialization list.

// constructor
Circle::Circle(int newx, int newy, int newradius) : Shape(newx, newy) {
	setRadius(newradius);
}

// accessors for the radius
int Circle::getRadius() { return radius; }
void Circle::setRadius(int newradius) { radius = newradius; }

// draw the circle
void Circle::draw() {
	cout << "Drawing a Circle at:(" << getX() << "," << getY() <<
		"), radius " << getRadius() << endl;
}