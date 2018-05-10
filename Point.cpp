#include <iostream>
#include "Point.h"
using namespace std;
 //That class represnt and return the point on the board
    
    
Point :: Point(int x, int y){ //constuctor
    i=x;
    j=y;
}
    //return x
int Point :: getX() const{
    return i;
}    
    //return y
int Point :: getY() const{
    return j;
}      


//return point 
Point& Point:: operator= (const Point& p){
    this->i = p.getX();
    this->j = p.getY();
    return *this;
}
Point::~Point() { }
