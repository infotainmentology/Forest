#include "./../include/PartyRequest.hpp"


PartyRequest :: PartyRequest(int aId, int mId, time_t tStmp)
{
    this->animalId = aId;
	this->meadowId = mId;
	this->timeStamp = tStmp;
}


//getters, setters
int PartyRequest :: getAnimalId()
{
	return this->animalId;
}

void PartyRequest :: setAnimalId(int id)
{
	this->animalId = id;
}

int PartyRequest :: getMeadowId()
{
	return this->meadowId;
}

void PartyRequest :: setMeadowId(int id)
{
	this->meadowId = id;
}

time_t PartyRequest :: getTimeStamp()
{
	return this->timeStamp;
}

void PartyRequest :: setTimeStamp(time_t timeStamp)
{
	this->timeStamp = timeStamp;
}