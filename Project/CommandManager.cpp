#include"CommandManager.h"
#include"God.h"

CommandManager::CommandManager(God* pPlayer,Scene* pScene)
{
	Player = pPlayer;
	scene = pScene;
}


std::vector<std::string> CommandManager::ParseCommand(std::string command)
{
	using namespace std;

	string tempo;
	stringstream ss(command); 

	vector<string> param;

	while (ss >> tempo)
	{
		param.push_back(tempo);
	}

	LastCommand = param;

	return param;
}

void CommandManager::ExecuteCommand(std::vector<std::string> command)
{
	using namespace std;

	if( command.size() > 0 )
	{
		if( command.front().find("destroy") != string::npos )
		{
			if( command.size() == 2 )
			{
				Planet* pPlanet = m_pScene->GetPlanet(command[1]);
				if( pPlanet )
				{
					Player->DestroyPopulation(*pPlanet);

					cout << "Population erased!" << endl << endl;
				}
				else
				{
					cout << "Planet " << command[1] << " does not exist. Type \"list\" to see planets." << endl << endl;
				}
			}
			else
			{
				cout << "Incorrect parameters" << endl << endl;
			}
		}
		else if( command.front().find("list") != string::npos)
		{
			for( auto& i : m_pScene->GetPlanets() )
			{
				cout << "Planet " << i->GetName() <<" with " << i->GetEntities().size() << " population" << endl;
			}
			cout << endl << endl;
		}
		else if( command.front().find("add") != string::npos)
		{
			if( command.size() == 4 )
			{
				Planet* pPlanet = m_pScene->GetPlanet(command[1]);
				EntityType type = m_pScene->ConvertType(command[2]);
				if( type == EntityType::UnknownType )
				{
					cout << "Incorrect entity type. Possible types are entity, animal, human or god." << endl << endl;
					LastCommand.clear();
					return;
				}
				int amount = stoi(command[3]);

				if( pPlanet )
				{
					Player->AddEntities(*pPlanet,type,amount);

					cout << "Entities added!" << endl << endl;
				}
				else
				{
					cout << "Planet " << command[1] << " does not exist. Type \"list\" to see the current planets." << endl << endl;
				}
			}
			else
			{
				cout << "Incorrect parameters" << endl << endl;
			}
		}
		else if( command.front().find("create") != string::npos)
		{
			Player->CreatePlanet();
			cout << "Planet created!" << endl << endl;
		}
		else if( command.front().find("exit") != string::npos)
		{
			exit(0);
		}
	}

	LastCommand.clear();
}

std::vector<std::string>& CommandManager::GetLastCommand()
{
	return LastCommand;
}
