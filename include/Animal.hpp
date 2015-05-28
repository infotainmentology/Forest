#ifndef Animal_hpp
#define Animal_hpp

#include <string>
#include <iostream>
#include <vector>
#include "PartyRequest.hpp"

class Animal {
    
  private:

  protected:
	int id;
	vector <PartyRequest*> requests;
	
    
  public:
    Animal(int id);
	void party();
	virtual int getSize();

//getters, setters
	int getId();
	void setId(int id);

};

#endif