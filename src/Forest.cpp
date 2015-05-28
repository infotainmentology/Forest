
#include <iostream>
//#include <cstdlib>
//#include <cstdio>
#include <ctime>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <typeinfo>
#include <mpi.h>
#include "./../include/Bunny.hpp"
#include "./../include/Animal.hpp"
#include "./../include/Teddy.hpp"
#include "./../include/Meadow.hpp"
#include "./../include/Constants.hpp"
#include "./../include/PartyRequest.hpp"

using namespace std;

int main(int argc, char **argv)
{

	//vector <Animal*> animals;
	Animal* me;
	vector <Meadow*> meadows;
 	int numOfThreads,tid;
	
    MPI_Status status;
    MPI_Init(&argc, &argv); 

    MPI_Comm_size( MPI_COMM_WORLD, &numOfThreads );
    MPI_Comm_rank( MPI_COMM_WORLD, &tid );


	int bunnyCount = 10;
	int teddyCount = 5;
	int meadowCount = 5;


	//we should take into consideration 
	//mpirun -np 10 -hostfiles hostFilesNames bunnyCount teddyCount meadowCount 
	//form of input
/*
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
*/
	if (tid == 0)
	{
		srand(time(NULL));

		for (int i = 0; i < meadowCount; ++i)
		{
		  meadows.push_back(new Meadow(i, rand() % maxMeadowCapacity));
	
		}
/*
		for (int i = 0; i < bunnyCount; ++i)
		{
			animals.push_back(new Bunny(i));

		}

		for (int i = 0; i < teddyCount; ++i)
		{
		    animals.push_back(new Teddy(bunnyCount + i));
		}
*/
		
		//broadcasting meadows
		for (int thNum = 1; thNum < numOfThreads; thNum++)
		{
		  for (int i=0; i< meadowCount; i++)
		  {
		    
		    int toSend[2];
		    toSend[0] = meadows.at(i)->getId();
		    toSend[1] = meadows.at(i)->getCapacity();
		    cout << toSend[0] << endl;
		    MPI_Send(&toSend, 2, MPI_INT, thNum, 100, MPI_COMM_WORLD);
		  }
		}
		  
	  }
	else //if not tid 0
	{
	    int toRecieve[2] = {0,0};
	    for (int i=0; i< meadowCount; i++)
	    {
		MPI_Recv(&toRecieve, 2, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);	  
		cout << "tid = " <<  tid << ",recieved " << toRecieve[0] <<  "+" << toRecieve[1] << endl;
		meadows.push_back(new Meadow(toRecieve[0], toRecieve[1]));
	    }
	}
	
	if (tid < bunnyCount)
	{
	    me = new Bunny(tid);
	}
	else
	{
	    me = new Teddy(tid);
	}
	

    MPI_Finalize();
}



