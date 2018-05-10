#include <iostream>
#include "newChar.h"
#include "exceptions.cpp"



using namespace std;


class Board{
    private :
        int size;
        newChar**board;
    public :
      
        Board(int n); //constructor
        Board(const Board& b); // copyConstructor
         newChar operator[](const Point &p) const;
         newChar& operator[](const Point &p);
         Board& operator= (char c);
         Board& operator=(const Board& b1);
         friend ostream& operator<< (ostream& os, const Board& b);
         ~Board();//destructor

        
};

 
