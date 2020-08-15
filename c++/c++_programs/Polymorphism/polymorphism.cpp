#include <iostream>

class Polygon
{
protected:
	float width, height;

public:
	void set_values(int a, int b)
	{
		width = a;
		height = b;
	}
	virtual float area() = 0;
};

class Rectangle: public Polygon
{
	float area()
	{
		return width * height;
	}
};

class Triangle : public Polygon
{
	float area()
	{
		return 0.5 * width * height;
	}
};



int main()
{
	const int NUM_OF_POLYGONS = 2;
	Polygon* polygons[NUM_OF_POLYGONS];
	Triangle tri;
	Rectangle rec;
	tri.set_values(5, 3);
	rec.set_values(5, 3);
	polygons[0] = &tri;
	polygons[1] = &rec;
	float areas[NUM_OF_POLYGONS];
	for (int i = 0; i < NUM_OF_POLYGONS; i++)
	{
		areas[i] = polygons[i]->area();
	}

	for (int i = 0; i < NUM_OF_POLYGONS; i++)
	{
		std::cout << "Area number " << i + 1 << "= " << areas[i] << std::endl;
	}
	getchar();
}