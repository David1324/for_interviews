#include <iostream>  
using namespace std;
class Shape {
protected:
	double x, y;
public:
	void set_dim(double i, double j = 0) {
		x = i;
		y = j;
	}
	virtual void show_area(void) {
		cout << "No area computation defined ";
		cout << "for this class.\n";
	}
};

class triangle : public Shape {
public:
	void show_area(void) {
		cout << "Triangle with height ";
		cout << x << " and base " << y;
		cout << " has an area of ";
		cout << x * 0.5 * y << ".\n";
	}
};

class square : public Shape {
public:
	void show_area(void) {
		cout << "Square with dimensions ";
		cout << x << "x" << y;
		cout << " has an area of ";
		cout << x *  y << ".\n";
	}
};

class circle : public Shape {
public:
	void show_area(void) {
		cout << "Circle with radius ";
		cout << x;
		cout << " has an area of ";
		cout << 3.14 * x * x;
	}
};

int main(void)
{
	Shape *p;
	triangle t;
	square s;
	circle c;
	Shape** arr = new Shape*[4];
	Shape* myShape = new Shape();
	triangle* tt = new triangle();
	square* ss = new square();
	circle* cc = new circle();

	arr[0] = &t;
	arr[1] = &s;
	arr[2] = &c;
	arr[3] = myShape;

	//Shape* temp = arr;
	for (int i = 0; i < 4; i++)
	{
		cout << "\n\nshape number " << i << endl;
		//temp->set_dim(10.0, 5.0);
		//temp->show_area();
		//temp++;
		arr[i]->set_dim(10.0, 5.0);
		arr[i]->show_area();
	}


	//p = &t;
	//p->set_dim(10.0, 5.0);
	//p->show_area();

	//p = &s;
	//p->set_dim(10.0, 5.0);
	//p->show_area();

	//p = &c;
	//p->set_dim(9.0);
	//p->show_area();

	getchar();
	return 0;
}