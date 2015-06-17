#include<string>

#pragma once

class RandomGenerator
{
public:

	RandomGenerator();

	char RandomChar();

	std::string RandomString(int length);

	int RandomNumber(int nUpperRange);

	int RandomNumberBetween(int nLowerRange, int nUpperRange);

	static RandomGenerator* GetRGen();

private:

	static RandomGenerator* time;
};
