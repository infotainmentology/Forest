
#include <iostream>
//#include <cstdlib>
//#include <cstdio>
#include <ctime>
#include <string.h>
#include <vector>
#include <typeinfo>
#include "Bunny.hpp"
#include "Animal.hpp"
#include "Teddy.hpp"
#include "Meadow.hpp"
#include "Constants.hpp"

using namespace std;

int main(int argc, char* argv[])
{

	vector <Animal*> animals;
	vector <Meadow*> meadows;

	int bunnyCount = 10;
	int teddyCount = 5;
	int meadowCount = 3;


	//we should take into consideration 
	//mpirun -np 10 -hostfiles hostFilesNames bunnyCount teddyCount meadowCount 
	//form of input
	if (argc >=3)
	{
		try
		{
			bunnyCount = atoi(argv[0]);
			teddyCount = atoi(argv[1]);
			meadowCount = atoi(argv[2]);
		}
		catch (...)
		{
			cerr << "Argv conversion unsuccessful" << endl;
		}
	}

	if (tid == 0)
	{
		srand(time(NULL));

		for (int i = 0; i < meadowCount; ++i)
		{
			meadows.push_back(new Meadow(i, rand() % maxMeadowCapacity));
		}

		for (int i = 0; i < bunnyCount; ++i)
		{
			animals.push_back(new Bunny(i));
		}

		for (int i = 0; i < teddyCount; ++i)
		{
			animals.push_back(new Teddy(bunnyCount + i));
		}
		//TODO:broadcast tle list to others
	}
	else
	{
		//TODO: mpilisten;
	}

	cout << "bunny size = " << animals.at(0)->getSize() << endl;

	return 0;
}

