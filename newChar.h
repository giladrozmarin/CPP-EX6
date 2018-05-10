#include <iostream>



using namespace std;

class newChar{
  
    private :
        char c;
    
    public :
        friend ostream& operator<< (ostream& os, const newChar& nc);
        newChar();
        newChar(char c);
        newChar(const newChar& nc);
        newChar& operator= (const char c);
        newChar& operator= (const  newChar& nc);
        operator char() const;

        
};

