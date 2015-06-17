#include "Entity.h"
#include"RandomGenerator.h"
Entity::Entity()
{
    int m_namelenght=RandomGenerator::GetRGen()->RandomNumberBetween(4,6);
	m_Name=RandomGenerator::GetRGen()->RandomString(m_namelenght);
	m_energy=RandomGenerator::GetRGen()->RandomNumber(100);

	double x = RandomGenerator::GetRGen()->RandomNumber(10000);
	double y = RandomGenerator::GetRGen()->RandomNumber(10000);
	m_position=Point2D(x,y);
	m_strenght=(int)m_energy*(RandomGenerator::GetRGen()->RandomNumber(5));
}

Entity::Entity(std::string name,double energy,double size,double weight,Point2D position)
{
	m_Name=name;
	m_energy=energy;
	m_position=position;
	m_strenght=(int)m_energy*RandomGenerator::GetRGen()->RandomNumber(5);

}

std::string Entity::GetName()
{
	return m_Name;
}
void Entity::SetName(std::string name)
{
	m_Name = name;
}

double Entity::GetEnergy()
{
	return m_energy;
}
void Entity::SetEnergy(double energy)
{
	m_energy = energy;
}

double Entity::GetSize()
{
	return m_size;
}
void Entity::SetSize(double size)
{
	m_size=size;
}

double Entity::GetWeight()
{
	return m_weight;
}
void Entity::Setweight(double weight)
{
	m_weight=weight;
}

Point2D Entity::GetPosition() const
{
	return m_position;
}
void Entity::SetPosition(Point2D position)
{
	m_position = position;
}

double Entity::GetStrength()
{
	return m_strenght;
}
void Entity::SetStrength(double strenght)
{
	m_size=strenght;
}

States Entity::GetState()
{
	return m_state;
}
void Entity::SetState(States state)
{
	m_state = state;
}

void Entity::Attack(Entity& otherEntity)
{
	int damage = RandomGenerator::GetRGen()->RandomNumber(m_strenght);
	double enemyenergy=otherEntity.GetEnergy();
	otherEntity.SetEnergy(enemyenergy-damage);
}

void Entity::Move(Point2D new_path)
{
	m_position.SetX(m_position.GetX()+new_path.GetX());
	m_position.SetY(m_position.GetY()+new_path.GetY());
}

void Entity::DoAction(std::unique_ptr<Planet>& pPlanet,Entity& otherEntity)
{
	Attack(otherEntity);
}
