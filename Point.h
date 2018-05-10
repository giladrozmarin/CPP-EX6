#include <iostream>
using namespace std;

class Point{
    private:
        int i;
        int j;
        
    public:
       // point();
        Point(int x, int y);
        int getX() const;
        int getY() const;
        Point& operator= (const Point& p);
        ~Point();
};
