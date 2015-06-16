#ifndef Animal_hpp
#define Animal_hpp

#include <string>
#include <iostream>
#include <vector>
#include <mpi.h>
#include <thread> 
#include "PartyRequest.hpp"
#include "Meadow.hpp"

//forward declaration needed
class Meadow;
class Animal {
    
  private:

  protected:
	int id;
	vector <PartyRequest*> requests;
	MPI_Status status;
	vector <Meadow*> meadows;
	int animalCount;
	int bunnyCount;
	int teddyCount;
	int meadowCount;
	
    
  public:
	Animal(int id);
	void party();
	void handleRecievingMessages();
	void broadcastPartyMsg();
	
//getters, setters
	virtual int getSize();
	int getId();
	void setId(int id);
	void setMeadows(vector <Meadow*> meadows);
	void setCounts(int ac, int bc, int tc, int mc);

};

#endif