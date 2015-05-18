#include "Meadow.hpp"

Meadow :: Meadow(int id, int capacity)
  {
   this->id = id;
   this->capacity = capacity;
  }

//getters, setters
int Meadow :: getlId()
{
	return this->id;
}

void Meadow :: setId(int id)
{
	this->id = id;
}

int Meadow :: getCapacity()
{
	return this->capacity;
}

void Meadow :: setCapacity(int capacity)
{
	this->capacity = capacity;
}
