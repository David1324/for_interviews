#include <iostream>

using namespace std;

void transformFnc(std::vector<PointF> basePoints, std::vector<PointF> targetPoints,
	PointF& offset, double rotation, double scale)
{
	std::vector<Line> basePointsLines;
	std::vector<Line> targetPointsLines;
	assert(basePoints.size() == targetPoints.size());
	int pointsNumber = basePoints.size();

	for (int i = 0; i < pointsNumber; i++)
	{
		for (int j = i + 1; j < pointsNumber; j++)
		{
			basePointsLines.push_back(Line(basePoints[i], basePoints[j]));
			targetPointsLines.push_back(Line(targetPoints[i], targetPoints[j]));
		}
	}
	std::vector<double> scalesVector;
	std::vector<double> rotationsVector;
	double baseCenterX = 0, baseCenterY = 0, targetCenterX = 0, targetCenterY = 0;
	for (std::vector<Line>::iterator it = basePointsLines.begin(), i = targetPointsLines.begin();
		it != basePointsLines.end(), i != targetPointsLines.end(); it++, i++)
	{
		scalesVector.push_back((*i).length() / (*it).length());
		baseCenterX += (*it).pointAt(0.5).x();
		baseCenterY += (*it).pointAt(0.5).y();
		targetCenterX += (*i).pointAt(0.5).x();
		targetCenterY += (*i).pointAt(0.5).y();
		double rotation;
		rotation = (*i).angleTo((*it));
		rotationsVector.push_back(rotation);
	}
	baseCenterX = baseCenterX / pointsNumber;
	baseCenterY = baseCenterY / pointsNumber;
	targetCenterX = targetCenterX / pointsNumber;
	targetCenterY = targetCenterY / pointsNumber;

	offset = PointF(targetCenterX - baseCenterX, targetCenterY - baseCenterY);
	scale = sum(scalesVector) / scalesVector.size();
	rotation = sum(rotationsVector) / rotationsVector.size();
}



int main()
{
	cout << "hello world" << endl;

	getchar();
	return 0;
}