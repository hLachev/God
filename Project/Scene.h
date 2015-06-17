#include<functional>
#include"Planet.h"
#include"Entity.h"
#include"Animal.h"
#include"Human.h"

#pragma once 

class Scene
{

public:

	std::vector<std::unique_ptr<Planet>>& GetPlanets();

	Planet* GetPlanet(std::string strPlanetName);

	std::unique_ptr<Entity> CreateEntity(EntityType type);

	EntityType ConvertType(std::string type);

private:


	std::vector<std::unique_ptr<Planet>> Planets;
};

extern Scene* m_pScene;
