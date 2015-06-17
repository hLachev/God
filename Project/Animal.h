#include"Entity.h"

#pragma once

class Animal: public Entity
{
public:

	Animal();

	void Sleep();
	void SearchForFood();
	void Eat();

	void Attack(Entity& otherentity);
	void Mate(std::unique_ptr<Planet>& p);

	virtual void DoAction(std::unique_ptr<Planet>& p,Entity& otherentity);

private:


};
