#ifndef Animal_hpp
#define Animal_hpp

#include <string>
#include <iostream>

class Animal {
    
  private:

  protected:
	int id;
    
  public:
    Animal(int id);
	void party();
	virtual int getSize();

//getters, setters
	int getId();
	void setId(int id);

};

#endif