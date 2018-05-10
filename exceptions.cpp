#include <exception>
#include <string>
#include "Point.h"

using namespace std;



class IllegalCoordinateException{
    private:
        const Point &p;
    public:
        IllegalCoordinateException(const  Point &p) : p(p){}


string theCoordinate() const{
    return string(to_string(p.getX()) + "," + to_string(p.getY()));
    
}
};
class IllegalCharException{
    private:
      const  char c;
    public:
     IllegalCharException(const char c) : c(c){}
    


// Throw an object:
char theChar() const {
        return c;
    }

};
