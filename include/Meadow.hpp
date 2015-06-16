#ifndef Meadow_hpp
#define Meadow_hpp

#include <string>
#include <iostream>
#include "Animal.hpp"


class Meadow
{
  private:
    int id;
    int maxCapacity;
    int capacity;

  protected:
    
  public:
	Meadow(int id, int maxCapacity);
	//int tryParty(Animal* animal);

	//getters, setters
	int getId();
	void setId(int id);
	int getCapacity();
	void setCapacity(int id);
  
};

#endif