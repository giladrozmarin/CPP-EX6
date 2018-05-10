
CXX=g++
CXXFLAGS=-std=c++17 -Wall -Werror -Wvla

all: Board.o Point.o newChar.o exceptions.o

Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

exceptions.o: exceptions.cpp exceptions.h
	$(CXX) $(CXXFLAGS) -c exceptions.cpp -o exceptions.o

Point.o:  Point.cpp Point.h
	$(CXX) $(CXXFLAGS) -c Point.cpp -o Point.o

newChar.o:  newChar.cpp newChar.h
	$(CXX) $(CXXFLAGS) -c Cell.cpp -o Cell.o
clean:
	rm *.o 
