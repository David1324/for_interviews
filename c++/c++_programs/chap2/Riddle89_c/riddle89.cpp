#include <iostream>
#include <vector>
//#include <utility>      // std::pair, std::make_pair
#include <algorithm>    // std::sort

#define START_X 1
#define END_X 2

using std::vector;
using std::pair;
using std::sort;
using std::sort;
using std::cout;
using std::endl;

class Point
{
public:
	float x;
	float y;
	Point() : x(0), y(0) {}
	Point(float x, float y) : x(x) , y(y) {}
	Point(const Point& p) { this->x = p.x; this->y = p.y; }
};

class Line
{
public:
	Point start_point;
	Point end_point;
	Line(Point start_point, Point end_point)
	{
		this->start_point = start_point;
		this->end_point = end_point;
	}
};

bool compareFunc(const pair<float, int> &a, const pair<float, int> &b) {
	bool main_compare = a.first < b.first;
	bool secondary_compare = a.second < b.second;
	if (a.first == b.first)
		return secondary_compare;
	else
		return main_compare;
}

void print_pairs(vector<pair<float, int>> pairs)
{
	int num_of_pairs = pairs.size();
	for (int i = 0; i < num_of_pairs; i++)
	{
		pair<float, int> current_pair = pairs[i];
		cout << "[" << current_pair.first << ", " << current_pair.second << "]" << endl;
	}
}

int calculate_max_count(vector<pair<float, int>> sorted_pairs)
{
	int counter = 0;
	int max_counter = 0;
	float max_point_x = 0;
	int num_of_pairs = sorted_pairs.size();
	for (int i = 0; i < num_of_pairs; i++)
	{
		pair<float, int> current_pair = sorted_pairs[i];
		if (current_pair.second == START_X)
			counter++;
		else
			counter--;
		if (counter > max_counter)
		{
			max_counter = counter;
			max_point_x = current_pair.first;
		}
	}
	return max_counter;
}

int main()
{
	vector<Line> lines;
	Point point_start1(2.5, -3.9);
	Point point_start2(3, 2);
	Point point_start3(9, 20);

	Point point_end1(3, 3.9);
	Point point_end2(7, 8);
	Point point_end3(30, 20);

	Line line1(point_start1, point_end1);
	Line line2(point_start2, point_end2);
	Line line3(point_start3, point_end3);

	lines.push_back(line1);
	lines.push_back(line2);
	lines.push_back(line3);

	int num_of_lines = lines.size();
	vector<pair<float, int>> pairs_x;
	for (int i = 0; i < num_of_lines; i++)
	{
		Line current_line = lines[i];
		float x_start = current_line.start_point.x;
		float x_end = current_line.end_point.x;
		pair<float, int> current_pair_x_start = std::make_pair(x_start, START_X);
		pair<float, int> current_pair_x_end = std::make_pair(x_end, END_X);
		pairs_x.push_back(current_pair_x_start);
		pairs_x.push_back(current_pair_x_end);
	}

	cout << "Original pairs:\n";
	print_pairs(pairs_x);
	cout << "\n\n";
	cout << "Sorted pairs:\n";
	sort(pairs_x.begin(), pairs_x.end(), compareFunc);
	print_pairs(pairs_x);

	cout << "\n\n";
	int max_counter = calculate_max_count(pairs_x);
	cout << "max_counter = " << max_counter << endl;

	getchar();
	return 0;
}