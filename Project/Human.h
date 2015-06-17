#include"Animal.h"

#pragma once

class Human : public Animal
{
public:

	Human();

	void Analyze();
	
	void Attack(Entity& otherentity);
	void Mate(std::unique_ptr<Planet>& p);
	virtual void DoAction(std::unique_ptr<Planet>& p,Entity& otherentity);

};
