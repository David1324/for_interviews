#include <iostream>
using namespace std;

class Square;  // forward declaration (since class Rectangle uses class Square in display function)

class Rectangle {
	int width, height;

public:
	Rectangle(int w = 1, int h = 1) :width(w), height(h){}
	//display is not a method of Rectangle! it is outsider function. you only declare it as a friend so it can access the private members of Rectangle
	friend void display(Rectangle &, Square &);

	//display_method is a method of Rectangle and hence can access private members
	void display_method(Rectangle &);
};

class Square {
	int side;

public:
	Square(int s = 1) :side(s){}
	friend void display(Rectangle &, Square &);
};

void display(Rectangle &r, Square &s) {
	cout << "Rectangle: " << r.width * r.height << endl;
	cout << "Square: " << s.side * s.side << endl;
}

void Rectangle::display_method(Rectangle &r) {
	cout << r.width * r.height << endl; //you can access private members width, height since "display" is a friend function
}

int main() {
	Rectangle rec(5, 10);
	Square sq(5);

	cout << "display as friend function" << endl;
	display(rec, sq);
	cout << "\n\n";
	cout << "display_method as method of Rectangle" << endl;
	rec.display_method(rec);

	getchar();
	return 0;
}