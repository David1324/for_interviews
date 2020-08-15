#include "Line.h"

//Line::Line(std::vector<double> point1, std::vector<double> point2)
//{
//	dim = point1.size();
//	double diff_points_size = 0;
//	for (int i = 0; i < dim; i++)
//	{
//		this->point1.push_back(point1[i]);
//		this->point2.push_back(point2[i]);
//		diff_points_size = diff_points_size + (point2[i] - point1[i])*(point2[i] - point1[i]);
//		this->unit_vec.push_back(point2[i] - point1[i]);
//	}
//	diff_points_size = sqrt(diff_points_size);
//	for (int i = 0; i < dim; i++)
//	{
//		this->unit_vec[i] = this->unit_vec[i] / diff_points_size;
//	}
//}



//std::vector<double> Line::calc_point_projection(std::vector<double> p)
//{
//	std::vector<double> vec_between_points;
//	for (int i = 0; i < dim; i++)
//	{
//		vec_between_points.push_back(p[i] - this->point1[i]);
//	}
//	double dot_product = 0;
//	for (int i = 0; i < dim; i++)
//	{
//		dot_product += vec_between_points[i] * this->unit_vec[i];
//	}
//	std::vector<double> point_projection;
//	for (int i = 0; i < dim; i++)
//	{
//		point_projection.push_back(this->point1[i] + dot_product * this->unit_vec[i]);
//	}
//	return point_projection;
//}
//
//bool Line::is_projection_of_point_between_edges(std::vector<double> p)
//{
//	std::vector<double> p_proj = calc_point_projection(p);
//	int i = 0;
//	double t1 = (p_proj[i] - point1[i]) / (point2[i] - point1[i]);
//	i = 1;
//	double t2 = (p_proj[i] - point1[i]) / (point2[i] - point1[i]);
//	double t = t1;
//	if (t >= 0 && t <= 1)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

Line::Line(Point2f point1, Point2f point2)
{
	this->p1 = point1;
	this->p2 = point2;
	Point2f vec = point2 - point1;
	float vec_norm = sqrt(vec.x*vec.x + vec.y*vec.y);
	this->unit_v = vec / vec_norm;
}

Point2f Line::calc_point_projection(Point2f p)
{
	Point2f vec_between_points = p - this->p1;
	float dot_product = vec_between_points.x * this->unit_v.x + vec_between_points.y * this->unit_v.y;
	Point2f point_projection = this->p1 + dot_product*this->unit_v;
	return point_projection;
}

bool Line::is_projection_of_point_between_edges(Point2f p)
{
	Point2f p_proj = calc_point_projection(p);
	int i = 0;
	float t1 = (p_proj.x - p1.x) / (p2.x - p1.x);
	i = 1;
	float t2 = (p_proj.y - p1.y) / (p2.y - p1.y);
	float t = t1;
	if (t >= 0 && t <= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}