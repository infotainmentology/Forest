#include "./../include/Animal.hpp"



void Animal :: handleRecievingMessages()
{	
    int toRecieve[5];
    int flag;
    bool programLoop = true;
    while(programLoop)
    {  
	MPI_Recv(&toRecieve, 5, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
	cout << "myId = " << id << " MPI status = " << status.MPI_TAG << " msg from = " <<  toRecieve[0] << endl;
    }
}

Animal::Animal(int id)
{
      this->id = id;
      //std::thread t1 = std::thread(&Animal::handleRecievingMessages, this);
      
     //std::thread msgHandler (handleRecievingMessages); 
    //party();
      //t1.join();
}



/**
 * this method is main loop for each animal
 */
void Animal :: party()
{
    //pthread_create(&tid, NULL, handleRecievingMessages, NULL);
    std::thread t1 = std::thread(&Animal::handleRecievingMessages, this);
     //broadcastPartyMsg();
	//TODO: code of algorithm here:
	/*
	*1) sleep some
	*2) randomly decide which meadow [1..meadowCount] to party on
	*3)	create a PartyRequest and broadcast
	*4) wait for response from all
	*5)srt currentPartyMeadow to most popular one. If more than 1 has the same no of requests, pich one with lower id
	*6)	sort all PartyRequest by timestamps
	*7) if you're first and there's still space on currentPartyMedow left, go to party \(^__^)/
	*/
}

void Animal :: broadcastPartyMsg()
{

    int toSend[5] = {0, 0, 0, 0, 0 };
    toSend[0] = id;
    for (int i=0; i<animalCount; i++)
    {
	if (i != id)
	{
	  cout << "myID = " << id << " sending to = " << i << endl;
	  MPI_Send(&toSend, 5, MPI_INT, id, 1, MPI_COMM_WORLD);
	}
	  
    }
}





int Animal :: getSize()
{
	return 0;
}

int Animal :: getId()
{
	return this->id;
}

void Animal :: setId(int id)
{
	this->id = id;
}

void Animal :: setMeadows(vector <Meadow*> meadows)
{
	this->meadows = meadows;
}

void Animal :: setCounts(int ac, int bc, int tc, int mc)
{
	this->animalCount = ac;
	this->bunnyCount = bc;
	this->teddyCount = tc;
	this->meadowCount = mc;
  
}
