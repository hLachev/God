#include<cmath>
#pragma once

class Point2D
{

public:

	Point2D();
	Point2D(double x, double y);

	double GetX() const;
	void SetX(double x);

	double GetY() const;
	void SetY(double y);

	double GetDistance(const Point2D& point1);
	double GetDistanceToStart();


private:
	double m_X,m_Y;
};
