#include"Animal.h"
#include"Planet.h"

Animal::Animal()
{
}

void Animal::Attack(Entity& otherentity)
{
	    int damage = RandomGenerator::GetRGen()->RandomNumber(m_strenght);
	    double enemyenergy=otherentity.GetEnergy();
	    otherentity.SetEnergy(enemyenergy-damage);
}

void Animal::Sleep()
{
	m_state = States::Sleeping;
}

void Animal::SearchForFood()
{
	m_state = States::SearchingForFood;
}

void Animal::Eat()
{
	m_state = States::Eating;
}

void Animal::Mate(std::unique_ptr<Planet>& p)
{
	p->GetEntityAdded()[EntityType::AnimalType]++;
}

void Animal::DoAction(std::unique_ptr<Planet>& p,Entity& otherentity)
{
	int number = RandomGenerator::GetRGen()->RandomNumber(5);
	switch(number)
	{
		case 1: Attack(otherentity); break;
		case 2: Sleep(); break;
		case 3: SearchForFood(); break;
		case 4: Eat(); break;
		case 5: Mate(p); break;
	};		 
}
