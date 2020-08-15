#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using std::ostream;
using std::cout;
using std::endl;
using std::abs;

class Line
{
private:
	int dim;
	vector<double> point;
	vector<double> unit_direction;

public:
	Line(int dim, vector<double> point, vector<double> unit_direction)
	{
		this->dim = dim;
		this->point = point;
		this->unit_direction = unit_direction;
	}

	Line(const Line& line)
	{
		this->dim = line.dim;
		this->point = line.point;
		this->unit_direction = line.unit_direction;
	}

	friend ostream& operator << (ostream& os, const Line& line)
	{
		//vector<double>::iterator i;

		os << "point: [";
		/*for (i = line.point.begin(); i != line.point.end(); i++)
		{
			double val = *i;
			os << val << ", ";
		}*/
		for (int i = 0; i < line.point.size(); i++)
		{
			os << line.point[i] << ", ";
		}
		os << "].";
		os << endl;

		os << "unit_direction: [";
		for (int i = 0; i < line.unit_direction.size(); i++)
		{
			os << line.unit_direction[i] << ", ";
		}
		os << "].";
		os << endl;
		return os;
	}

	bool is_parallel(const Line& line)
	{
		if (line.dim != dim) return false;
		double dot_product = 0;
		vector<double>::iterator i;
		for (int i=0 ; i< unit_direction.size() ; i++)
		{
			dot_product += unit_direction[i] * line.unit_direction[i];
		}

		double epsilon = 10 ^ -10;
		if ((dot_product - 1) < epsilon)
			return true;
		return false;
	}
};

int main()
{
	int dim = 2;
	vector<double> point;
	vector<double> unit_direction;
	point.push_back(3);
	point.push_back(4);
	unit_direction.push_back(3);
	unit_direction.push_back(3);
	Line my_line(dim, point, unit_direction);

	getchar();
	return 0;
}