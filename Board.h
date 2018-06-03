#include <iostream>
#include "newChar.h"
#include "exceptions.cpp"
#include <fstream>
#include <string>

#pragma once
using namespace std;

struct RGB {
    uint8_t red, green, blue;
    public:
        RGB() {}
        RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

class Board{
    private :
         int Size;
       
    public :
        newChar** board;
        Board(); //constructor defult
        Board(int n); //constructor
        Board(const Board& b); // copyConstructor
         newChar operator[](const Point &p) const;
         newChar& operator[](const Point &p);
         Board& operator= (char c);
         Board& operator=(const Board& b1);
         friend ostream& operator<< (ostream& os, const Board& b);
         friend istream& operator>> (istream& os,Board& b);
         bool isExists(string file);
         const string draw(int n);
         int size() const;
         
         ~Board();//destructor
        

        
};
inline istream &operator>>(istream &is,  Board& b) {  //input   
        string line;
        cin>>line;
       int n = line.length();
        Board temp(n);
        for (int i = 0; i < temp.size(); i++) {
            for (int j = 0; j < temp.size(); j++){ 
                    temp.board[i][j]=line[j];
                }
                //line="";
                cin>>line;
            }
        b=temp;
        return is;
    }
