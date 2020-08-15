#pragma once
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#define w 400

using namespace cv;

class Triangle
{
private:
	//std::vector<double> point1;
	//std::vector<double> point2;
	//std::vector<double> point3;
	Point2f p1;
	Point2f p2;
	Point2f p3;
	int dim;
	void draw_line(Mat img, Point2f start, Point2f end);

public:
	//Triangle(std::vector<double> point1, std::vector<double> point2, std::vector<double> point3);
	//bool is_point_inside(std::vector<double> point);
	Triangle(Point2f point1, Point2f point2, Point2f point3);
	bool is_point_inside(Point2f point);
	void draw(Mat img);
};
