#include "./../include/Meadow.hpp"

Meadow :: Meadow(int id, int maxCapacity)
  {
   this->id = id;
   this->maxCapacity = maxCapacity;
   this->capacity = maxCapacity;
   
  }

//getters, setters
int Meadow :: getId()
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
