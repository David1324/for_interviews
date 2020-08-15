#include <iostream>
#include <vector>
#include <utility>      // std::pair, std::make_pair

using std::cout;
using std::endl;
using std::vector;
using std::pair;

class Shape
{
private:
	float x, y;

public:
	Shape(float x, float y) : x(x), y(y) {}
	float getX() { return x; }
	float getY() { return y; }
	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	virtual void draw() = 0;
};

class Rectangle : public Shape
{
private:
	float width, height;

public:
	Rectangle(float x, float y, float width, float height) : Shape(x,y)
	{
		this->width = width;
		this->height = height;
	}
	float calc_area() { return width * height; }
	vector<pair<float, float>> calc_coordinates()
	{
		pair<float,float> bottom_left_point = std::make_pair(getX(), getY());
		pair<float, float> top_left_point = std::make_pair(getX(), getY()+height);
		pair<float, float> top_right_point = std::make_pair(getX() + width, getY() + height);
		pair<float, float> bottom_right_point = std::make_pair(getX() + width, getY());
		vector<pair<float, float>> points;
		points.push_back(bottom_left_point);
		points.push_back(top_left_point);
		points.push_back(top_right_point);
		points.push_back(bottom_right_point);
		return points;
	}
	void draw()
	{
		cout << "Drawing rectange with the following 4 points:" << endl;
		vector<pair<float, float>> points = calc_coordinates();
		cout << "bottom left point = (" << points[0].first << ", " << points[0].second << ")" << endl;
		cout << "top left point = (" << points[1].first << ", " << points[1].second << ")" << endl;
		cout << "bottom right point = (" << points[2].first << ", " << points[2].second << ")" << endl;
		cout << "top right point = (" << points[3].first << ", " << points[3].second << ")" << endl;
		cout << "\n\n";
	}
};

class Circle : public Shape
{
private:
	float radius;
public:
	Circle(float x,float y,float radius) : Shape(x,y)
	{
		this->radius = radius;
	}
	void draw()
	{
		cout << "Drawing circle centered at [" << getX() << ", " << getY() << "] " << "with radius = " << radius << endl;
		cout << "\n\n";
	}
};


int main()
{
	vector<Shape*> shapes;
	Rectangle* my_rectangle = new Rectangle(3, 2, 40, 50);
	Circle* my_circle = new Circle(4, 5, 200);
	shapes.push_back(my_rectangle);
	shapes.push_back(my_circle);

	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->draw();
	}
	getchar();
	return 0;
}