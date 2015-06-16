#------------------------------------------------------------------------------

SOURCE = ./include/Meadow.hpp ./src/Meadow.cpp \
	./include/Animal.hpp ./src/Animal.cpp \
	./include/Bunny.hpp ./src/Bunny.cpp \
	./include/Teddy.hpp ./src/Teddy.cpp \
	./include/PartyRequest.hpp ./src/PartyRequest.cpp \
	./src/Forest.cpp ./include/Constants.hpp
MYPROGRAM = forest
CC = mpic++

#------------------------------------------------------------------------------



all: $(MYPROGRAM)


$(MYPROGRAM): $(SOURCE)
	$(CC) -std=c++11 -lpthread $(SOURCE) -o$(MYPROGRAM)

clean:
	rm -f $(MYPROGRAM)

