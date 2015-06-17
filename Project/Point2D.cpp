#include"Point2D.h"

Point2D::Point2D():m_X(0),m_Y(0) {}

Point2D::Point2D(double x, double y):m_X(x),m_Y(y) {}

double Point2D::GetX() const
{
	return m_X;
}

void Point2D::SetX(double x)
{
	m_X = x;
}

double Point2D::GetY() const
{
	return m_Y;
}

void Point2D::SetY(double y)
{
	m_Y = y;
}


double Point2D::GetDistance(const Point2D& p)
{
	return sqrt((p.GetX()-m_X)*(p.GetX()-m_X)+(p.GetY()-m_Y)*(p.GetY()-m_Y));
}

double Point2D::GetDistanceToStart()
{
	return sqrt(m_X*m_X+m_Y*m_Y);
}
