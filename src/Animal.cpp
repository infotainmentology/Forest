#include "./../include/Animal.hpp"


Animal::Animal(int id)
{
    this->id = id;
}

void Animal :: party()
{
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