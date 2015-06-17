#include"Scene.h"
#include<sstream>

class God;

class CommandManager
{
public:

	CommandManager(God* pPlayer,Scene* pScene);

	std::vector<std::string> ParseCommand(std::string command);
	void ExecuteCommand(std::vector<std::string> commands);

	std::vector<std::string>& GetLastCommand();

private:

	God* Player;
	Scene* scene;

	std::vector<std::string> LastCommand;
};
