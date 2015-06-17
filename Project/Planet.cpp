#include"Planet.h"


Planet::Planet()
{

}

std::vector<std::unique_ptr<Entity>>& Planet::GetEntities()
{
	return m_vEntities;
}

std::map<EntityType, int>& Planet::GetEntityAdded()
{
	return m_EntitiesToBeAdded;
}

bool Planet::EntitesComparator(const std::unique_ptr<Entity>& ent1,const std::unique_ptr<Entity>& ent2)
{
	return ent1->GetPosition().GetDistanceToStart() > ent2->GetPosition().GetDistanceToStart();
}

void Planet::SortEntities()
{
	using namespace std::placeholders;
	sort(m_vEntities.begin(),m_vEntities.end(),std::bind(&Planet::EntitesComparator,this,_1,_2));
}
