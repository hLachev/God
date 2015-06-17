#include<string>
#include<iostream>
#include"Point2D.h"
#include"RandomGenerator.h"
#include<memory>

#pragma once 

class Planet;

enum class EntityType
{
	BasicEntity,
	AnimalType,
	HumanType,
	GodType,
	UnknownType
};

enum class States
{
	Unknown,
	Moving,
	Attacking,
	Eating,
	SearchingForFood,
	Sleeping,
	Analyzing
};

class Entity
{
public:

	Entity();
	Entity(std::string name,double energy,double size,double weight,Point2D position);

	std::string GetName();
	void SetName(std::string name);

	double GetEnergy();
	void SetEnergy(double energy);

	double GetSize();
	void SetSize(double size);

	double GetWeight();
	void Setweight(double weight);

	Point2D GetPosition() const;
	void SetPosition(Point2D position);

	double GetStrength();
	void SetStrength(double strength);

	States GetState();
	void SetState(States state);

	void Attack(Entity& otherEntity);

	void Move(Point2D new_path);

    virtual void DoAction(std::unique_ptr<Planet>& pPlanet,Entity& otherEntity);

protected:
	std::string m_Name;
	double m_energy;
	double m_size;
	double m_weight;
	Point2D m_position;
	int m_strenght;
	States m_state;
};
