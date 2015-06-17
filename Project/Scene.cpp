#include"Scene.h"
#include"God.h"

Scene* m_pScene = nullptr;

std::vector<std::unique_ptr<Planet>>& Scene::GetPlanets()
{
	return Planets;
}

 Planet* Scene::GetPlanet(std::string strPlanetName)
{
	for(auto& i : Planets )
	{
		if( !i->GetName().compare(strPlanetName) )
		{
			return i.get();
		}
	}

	return nullptr;
}

std::unique_ptr<Entity> Scene::CreateEntity(EntityType type)
{
	using namespace std;

	unique_ptr<Entity> m_Entity;

	switch( type )
	{
		case EntityType::BasicEntity :
		{
			unique_ptr<Entity> pNewEntity(new Entity());
				
			m_Entity = move(pNewEntity);

			break;
		}

		case EntityType::AnimalType :
		{
			unique_ptr<Entity> pNewEntity(new Animal());
				
			m_Entity = move(pNewEntity);

			break;

		}

		case EntityType::HumanType :
		{
			unique_ptr<Entity> pNewEntity(new Human());
				
			m_Entity = move(pNewEntity);

			break;
		}

		case EntityType::GodType :
		{
			unique_ptr<Entity> pNewEntity(new God());
				
			m_Entity = move(pNewEntity);

			break;
		}
	}

	return m_Entity;

}


EntityType Scene::ConvertType(std::string type)
{
	EntityType t_converted = EntityType::UnknownType;

	if( type.find("entity") != std::string::npos )
	{
		t_converted = EntityType::BasicEntity;
	}
	else if( type.find("animal") != std::string::npos)
	{
		t_converted = EntityType::AnimalType;
	}
	else if( type.find("human") != std::string::npos)
	{
		t_converted = EntityType::HumanType;
	}
	else if( type.find("god") != std::string::npos)
	{
		t_converted = EntityType::GodType;
	}

	return t_converted;
}
