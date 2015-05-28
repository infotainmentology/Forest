#ifndef PartyRequest_hpp
#define PartyRequest_hpp

#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class PartyRequest {
    
  private:
	int animalId;
	int meadowId;
	time_t timeStamp;

  protected:
    
  public:
	PartyRequest(int aId, int mId, time_t tStmp);

//getters, setters
	int getAnimalId();
	void setAnimalId(int id);
	int getMeadowId();
	void setMeadowId(int id);
	time_t getTimeStamp();
	void setTimeStamp(time_t timeStamp);

};

#endif