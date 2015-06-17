#include<vector>
#include"Entity.h"
#include<map>
#include<functional>
#include<algorithm>

using namespace std::placeholders;

#pragma once

class Planet: public Entity
{
public:

	Planet();

	void SortEntities();

	bool EntitesComparator(const std::unique_ptr<Entity>& ent1,const std::unique_ptr<Entity>& ent2);

	std::vector<std::unique_ptr<Entity>>& GetEntities();

	std::map<EntityType, int>& GetEntityAdded();

private:

	std::vector<std::unique_ptr<Entity>> m_vEntities;
	std::map<EntityType, int> m_EntitiesToBeAdded;
};
