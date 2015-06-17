#include"Human.h"
#include"Planet.h"
#include"Scene.h"

#pragma once

class God : public Human
{
public:
	void CreatePlanet();
	void DestroyPopulation(Planet& planet);
	void AddEntities(Planet& planet, EntityType type, int amount);
};
