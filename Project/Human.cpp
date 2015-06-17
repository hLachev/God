#include"Human.h"
#include"Scene.h"

Human::Human()
{
}

void Human::Analyze()
{
	m_state = States::Analyzing;
}

void Human::Attack(Entity& otherentity)
{
	    int damage = RandomGenerator::GetRGen()->RandomNumber(m_strenght);
	    double enemyenergy=otherentity.GetEnergy();
	    otherentity.SetEnergy(enemyenergy-damage);
}

void Human::Mate(std::unique_ptr<Planet>& p)
{
	p->GetEntityAdded()[EntityType::HumanType]++;
}

void Human::DoAction(std::unique_ptr<Planet>& p,Entity& otherentity)
{
	int number = RandomGenerator::GetRGen()->RandomNumber(6);
	switch(number)
	{
		case 1: Attack(otherentity); break;
		case 2: Sleep(); break;
		case 3: SearchForFood(); break;
		case 4: Eat(); break;
		case 5: Mate(p); break;
		case 6: Analyze(); break;
	};
}
