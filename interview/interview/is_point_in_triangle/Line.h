#pragma once
#include <vector>
#include <math.h> 
#include <opencv2/opencv.hpp>
using cv::Point2f;
using std::vector;



class Line
{
private:	
	vector<double> point1;
	vector<double> point2;
	vector<double> unit_vec;
	Point2f p1;
	Point2f p2;
	Point2f unit_v;
	int dim;

public:
	//Line(vector<double> point1, vector<double> point2);
	//vector<double> calc_point_projection(vector<double> p);
	//bool is_projection_of_point_between_edges(vector<double> p);
	Line(Point2f point1, Point2f point2);
	Point2f calc_point_projection(Point2f p);
	bool is_projection_of_point_between_edges(Point2f p);
};
