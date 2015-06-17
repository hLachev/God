#include"RandomGenerator.h"

RandomGenerator* RandomGenerator::time = nullptr;

RandomGenerator::RandomGenerator()
{}

char RandomGenerator::RandomChar()
{
	char randomchar;

	const int downAsciiCode = 97;
	const int upAsciiCode = 122;

	randomchar = static_cast<char>(RandomNumberBetween(downAsciiCode,upAsciiCode));
	
	

	return randomchar;

}

std::string RandomGenerator::RandomString(int length)
{
	std::string name;

	name.resize(length);

	for( int i = 0; i < length; i++)
	{
		name[i] = RandomChar();
	}

	return name;
}

int RandomGenerator::RandomNumber(int max)
{
	int number = rand() % max;
	
	return number+1;
}

int RandomGenerator::RandomNumberBetween(int min, int max)
{
	int number = rand() % (max-min);
	
	return min+number;
}

RandomGenerator* RandomGenerator::GetRGen()
{
	if( time == nullptr )
	{
		time  = new RandomGenerator;
	}
		
	return time;
}
