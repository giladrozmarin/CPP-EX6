#include "Board.h"
#include <iostream>
using namespace std;

//constructor
Board:: Board(int n): size(n){ //ask for size to build board 
  this->board = new newChar*[n];//new board
    int i;
    for(i = 0; i < n; i++)
        this->board[i] = new newChar[n];//Initializing the board put .
}
//copy constructor
Board::Board(const Board& b){
    this->size = b.size;
    this->board = new newChar*[this->size];
    int i, j;
    for(i = 0; i < this->size; i++){
        this->board[i] = new newChar[this->size];
        for(j = 0; j < this->size; j++)
            this->board[i][j] = b.board[i][j];
    }
}


//read only
 newChar Board::operator[](const Point &p) const { 
    return board[p.getX()][p.getY()];
}
//change value
 newChar& Board::operator[](const Point &p) { 
    if ( (p.getY() >= size || p.getY() < 0)||(p.getX() >= size || p.getX() < 0)){//check legal point
        throw IllegalCoordinateException(p);
    }
        return board[p.getX()][p.getY()];
}

Board& Board::operator= (char c){
    
    newChar dc(c);
    int i, j;
    for(i = 0; i < this->size; i++)
        for(j = 0; j < this->size; j++)
            this->board[i][j] = dc;
    return *this;
}

Board& Board::operator=(const Board& b1){
    
     if (this==&b1){
            return *this;
     }
    this->~Board();
    size = b1.size;
    board = new newChar*[size];  
	for (int i = 0; i < size; i++){
		board[i] = new newChar[size];
        for (int j = 0; j < size; j++) 
            board[i][j] = b1.board[i][j];
    }
    return *this;
        }
//toString   
ostream& operator<< (ostream& os, const Board& b){
    int i, j;
    for(i = 0; i < b.size; i++){
        for(j = 0; j < b.size; j++)
            os << b.board[i][j];
        os << endl;
    }
    return os;
}
//destructor
Board::~Board(){
    int i;
    for(i = 0; i< this->size; i++)
    	delete[] board[i]; //This part was allocated with new[], so we use delete[]
    delete[] board;
}
