#include <iostream>
#include "newChar.h"
//#include "IllegalCoordinateException.cpp"
#include "exceptions.cpp"


using namespace std;


    newChar::newChar(){ //constructor
     c='.';   
    }
    //copy constructor
    newChar::newChar(const char c) {
    this->operator =(c);
 }
    newChar::newChar(const newChar& nc) {
    this->c = nc.c;
}
    
  
    newChar& newChar::operator= (const char c1){ // chek legalCharException 
        if(c1!='X' && c1!='O' && c1!='.'){
            throw IllegalCharException(c1);
        }
        else{
            c=c1;
        }
        return *this;
    }

   newChar& newChar::operator= (const newChar& nc){
    this->c = nc.c;
    return *this;
}

ostream& operator<< (ostream& os, const newChar& nc){
    return os << nc.c;
}

newChar::operator char() const{
    return c;
}
