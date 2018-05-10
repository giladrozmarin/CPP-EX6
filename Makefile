CCX=g++ -std=c++11


all: Board.o Point.o newChar.o exceptions.o
		$(CCX) main.cpp *.o
		
Board.o: Board.cpp Board.h
		$(CCX) -c Board.cpp
		
Point.o: Point.cpp Point.h
		$(CCX) -c Point.cpp
		
newChar.o: newChar.cpp newChar.h
		$(CCX) -c newChar.cpp

exceptions.o: exceptions.cpp
		$(CCX) -c exceptions.cpp

		
Clean:
		rm *.o 
