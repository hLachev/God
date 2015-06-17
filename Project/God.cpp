#include"God.h"


void God::CreatePlanet()
{
	std::unique_ptr<Planet> m_Planet(new Planet);

	m_pScene->GetPlanets().push_back(std::move(m_Planet));
}

void God::DestroyPopulation(Planet& planet)
{
	planet.GetEntities().erase(planet.GetEntities().begin(),planet.GetEntities().end());
}

void God::AddEntities(Planet& p, EntityType type, int number)
{
	for(int i = 0; i < number;i++)
	{
		std::unique_ptr<Entity> pEntity = move(m_pScene->CreateEntity(type));

		p.GetEntities().push_back(std::move(pEntity));
	}
}
