#include"Moving.h"

const double dist = 31;
const int LowerBoarder = 0;
const int UpperBoarder = 150;
const int MoveRate = 30;

bool Moving::Isclose(const Entity& x1,const Entity& y2)
{
	return  x1.GetPosition().GetDistance(y2.GetPosition()) < dist;
}

void Moving::Move(Entity& var)
{
	double dx = RandomGenerator::GetRGen()->RandomNumber(MoveRate);
	double dy = RandomGenerator::GetRGen()->RandomNumber(MoveRate);

	if( var.GetPosition().GetX()+dx < LowerBoarder || var.GetPosition().GetX()+dx >UpperBoarder  )
	{
		dx = 0;
	}
	if( var.GetPosition().GetY()+dy < LowerBoarder || var.GetPosition().GetY()+dy >UpperBoarder)
	{
		dy = 0;
	}
	
	var.Move(Point2D(dx,dy));
}
