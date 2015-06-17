#include"Simulator.h"

Simulator::Simulator()
{
	m_pScene = new Scene;
	m_pPlayer = new God;
	m_pPhysics = new Moving;
	Manager = new CommandManager(m_pPlayer,m_pScene);
}

void Simulator::Run()
{
	using namespace std;

	unique_ptr<Planet> pPlanet(new Planet());

	m_pScene->GetPlanets().push_back(move(pPlanet));

	m_pPlayer->AddEntities(*(m_pScene->GetPlanets().front()),EntityType::HumanType,200);

	cout << "Hello," << m_pPlayer->GetName() << endl;

	std::thread PlayerInputThread(&Simulator::GetCommand,this);

	while(true)
	{
		if( ExecuteCommand )
		{
			Manager->ExecuteCommand(Manager->GetLastCommand());
			ExecuteCommand = false;
		}

		Update();
	}

	PlayerInputThread.join();
}

void Simulator::GetCommand()
{
	while( true)
	{
		static bool bShouldShow = true;
		if( bShouldShow && !ExecuteCommand )
		{		
			ExecuteCommand = false;
			bShouldShow = false;

			PrintOptions();

			std::string command;
			getline(std::cin,command);

			Manager->ParseCommand(command);
		
			ExecuteCommand = true;
			bShouldShow = true;	
		}
	}
}

void Simulator::PrintOptions()
{
	using namespace std;

	cout << "You can choose from the following options:" << endl;
	cout << "Type \"add <planet name> <entity,animal,human or god> <amount of entities>\" to add population to a planet" << endl;
	cout << "Type \"destroy <planet name>\" to destroy planet's population" << endl;
	cout << "Type \"list\" to print the current planets with their populations" << endl;
	cout << "Type \"create\" to create a new planet" << endl;
	cout << "Type \"exit\" to exit " << endl;
}

void Simulator::Update()
{

	for( auto& i: m_pScene->GetPlanets() )
	{
		
		for( auto it = i->GetEntityAdded().begin();it!=i->GetEntityAdded().end();it++)
		{
			for( int j = 0; j < it->second;j++)
			{
				std::unique_ptr<Entity> pEntity = move(m_pScene->CreateEntity(it->first));

				i->GetEntities().push_back(std::move(pEntity));
			}
		}

		i->GetEntityAdded().clear();
	}

	for( auto& i: m_pScene->GetPlanets() )
	{
		for(auto it = i->GetEntities().begin(); it!= i->GetEntities().end();it++)
		{
				m_pPhysics->Move(*(*it));
		}
	}

	for( auto& k: m_pScene->GetPlanets() )
	{
		for(auto it = k->GetEntities().begin(); it!= k->GetEntities().end();it++)
		{
			auto nextEntity = it;
			nextEntity++;

			if( nextEntity != k->GetEntities().end() && m_pPhysics->Isclose(*(*it),*(*nextEntity)) )
			{
				(*it)->DoAction(k,*(*nextEntity));
			}
		}
	}
}
