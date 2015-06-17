#include<map>
#include<thread>
#include"RandomGenerator.h"
#include"Scene.h"
#include"God.h"
#include"Moving.h"
#include"CommandManager.h"

#pragma once

class Simulator
{
public:

	Simulator();

	void GetCommand();

	void Run();

	void Update();

	void PrintOptions();

private:

	Moving* m_pPhysics;

	God* m_pPlayer;

	CommandManager* Manager;

	bool ExecuteCommand;
};
