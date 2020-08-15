#include "Triangle.h"
#include "Line.h"

//Triangle::Triangle(std::vector<double> point1, std::vector<double> point2, std::vector<double> point3)
//{
//	dim = point1.size();
//	for (int i = 0; i < dim; i++)
//	{
//		this->point1.push_back(point1[i]);
//		this->point2.push_back(point2[i]);
//		this->point3.push_back(point3[i]);
//	}	
//}

Triangle::Triangle(Point2f point1, Point2f point2, Point2f point3)
{
	this->p1 = point1;
	this->p2 = point2;
	this->p3 = point3;
}

//bool Triangle::is_point_inside(std::vector<double> point)
//{
//	Line* line_p1_p2 = new Line(this->p1, this->p2);
//	Line* line_p2_p3 = new Line(this->p2, this->p3);
//	Line* line_p3_p1 = new Line(this->p3, this->p1);
//	bool is_point_projection_between_point1_to_point2 = line_p1_p2->is_projection_of_point_between_edges(point);
//	bool is_point_projection_between_point2_to_point3 = line_p2_p3->is_projection_of_point_between_edges(point);
//	bool is_point_projection_between_point3_to_point1 = line_p3_p1->is_projection_of_point_between_edges(point);
//	if (is_point_projection_between_point1_to_point2 && is_point_projection_between_point2_to_point3 && is_point_projection_between_point3_to_point1)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

bool Triangle::is_point_inside(Point2f point)
{
	Line* line_p1_p2 = new Line(this->p1, this->p2);
	Line* line_p2_p3 = new Line(this->p2, this->p3);
	Line* line_p3_p1 = new Line(this->p3, this->p1);
	bool is_point_projection_between_point1_to_point2 = line_p1_p2->is_projection_of_point_between_edges(point);
	bool is_point_projection_between_point2_to_point3 = line_p2_p3->is_projection_of_point_between_edges(point);
	bool is_point_projection_between_point3_to_point1 = line_p3_p1->is_projection_of_point_between_edges(point);
	if (is_point_projection_between_point1_to_point2 && is_point_projection_between_point2_to_point3 && is_point_projection_between_point3_to_point1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Triangle::draw(Mat img)
{
	
	draw_line(img, p1, p2);
	draw_line(img, p2, p3);
	draw_line(img, p3, p1);

}

void Triangle::draw_line(Mat img, Point2f start, Point2f end)
{
	int thickness = 3;
	int lineType = LINE_8;

	line(img,
		start,
		end,
		Scalar(0, 255, 0),
		thickness,
		lineType);
}