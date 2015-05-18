#ifndef Meadow_hpp
#define Meadow_hpp

#include <string>
#include <iostream>
#include "Animal.hpp"


class Meadow
{
  private:
    int id;
    int capacity;

  protected:
    
  public:
    Meadow(int id, int capacity);
	int tryParty(Animal* animal);

	//getters, setters
	int getlId();
	void setId(int id);
	int getCapacity();
	void setCapacity(int id);
  
};

#endif