#include "Board.h"
#include <iostream>
#include <cmath>

using namespace std;


//constructor
Board:: Board(){ //ask for Size to build board 
Size  = 0;
  this->board = new newChar*[Size];//new board
    int i;
    for(i = 0; i < Size; i++)
        this->board[i] = new newChar[Size];//Initializing the board put .
}

Board:: Board(int n): Size(n){ //ask for Size to build board 
  this->board = new newChar*[n];//new board
    int i;
    for(i = 0; i < n; i++)
        this->board[i] = new newChar[n];//Initializing the board put .
}
//copy constructor
Board::Board(const Board& b){
    this->Size = b.Size;
    this->board = new newChar*[this->Size];
    int i, j;
    for(i = 0; i < this->Size; i++){
        this->board[i] = new newChar[this->Size];
        for(j = 0; j < this->Size; j++)
            this->board[i][j] = b.board[i][j];
    }
}

//read only
 newChar Board::operator[](const Point &p) const { 
    return board[p.getX()][p.getY()];
}
//change value
 newChar& Board::operator[](const Point &p) { 
    if ( (p.getY() >= Size || p.getY() < 0)||(p.getX() >= Size || p.getX() < 0)){//check legal point
        throw IllegalCoordinateException(p);
    }
        return board[p.getX()][p.getY()];
}

Board& Board::operator= (char c){
    
    newChar dc(c);
    int i, j;
    for(i = 0; i < this->Size; i++)
        for(j = 0; j < this->Size; j++)
            this->board[i][j] = dc;
    return *this;
}

Board& Board::operator=(const Board& b1){
    
     if (this==&b1){
            return *this;
     }
    this->~Board();
    Size = b1.Size;
    board = new newChar*[Size];  
	for (int i = 0; i < Size; i++){
		board[i] = new newChar[Size];
        for (int j = 0; j < Size; j++) 
            board[i][j] = b1.board[i][j];
    }
    return *this;
        }


//destructor
Board::~Board(){
    int i;
    for(i = 0; i< this->Size; i++)
    	delete[] board[i]; //This part was allocated with new[], so we use delete[]
    delete[] board;
}

//check if the file is exist
bool Board::isExists(string file) {
    ifstream infile(file);
    return infile.good();
}


const string Board :: draw(int n){  
    int num_pic = 1;
    const int dimx = n, dimy = n;
    unsigned int vertex=0;
     int width = cell / 5;
    int red_board, green_board, blue_board;
    int cell = n / Size ; 
    string filename = "Gamepic"+to_string(num_pic)+".ppm";
    RGB image[dimx*dimy];
    
    //backGround of the board
    for (int j = 0; j < dimy; ++j)  {  // row
        for (int i = 0; i < dimx; ++i) { // column
         vertex = dimx*j+i;
            image[vertex].red = (100);
            image[vertex].green = (100);
            image[vertex].blue = (100);
        }
    }
    //bounds
    for (int i = 0; i <dimx; ++i) {//row
        for (int j = 0; j < dimx; ++j) {//column
            if(i%(dimx /Size) == 0 || j%(dimx /Size) == 0  || i%(dimx-5/Size) == 0|| j%(dimx-5/Size) == 0) {
                image[dimx*i + j].red = 0;
                image[dimx*i + j].blue = 0;
                image[dimx*i + j].green = 0;
            }
        }
    }
    
    
       // X
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            char cur = board[i][j].getChar();

            for (int k = i*cell+width; k < i*cell+cell-width; ++k) {
                for (int y = j*cell+width; y < j*cell+cell-width; ++y) {
                    image[dimx*j+i].red = red_board;
                    image[dimx*j+i].blue = blue_board;
                    image[dimx*j+i].green = green_board; 
                }
            }
            //for "X"
            if(cur == 'X'){    
                int Right = j*cell+cell-width-1;
                int Left = j*cell+width;
                int q = 0;
                int thickLine = 0;
                
                for (int p = i*cell+width; p < i*cell+cell-width; ++p) {
                    //left diagonal
                    while(thickLine != 10){
                    image[dimx*p+Left+q + thickLine].red = (23);
                    thickLine++;
                    }
                    thickLine = 0;
                    while(thickLine != 10){
                    image[dimx*p+Left+q + thickLine].green = (150);
                    thickLine++;
                    }
                    while(thickLine != 10){
                    image[dimx*p+Left+q + thickLine].blue = (45);
                    thickLine++;
                    }
                    
                    //right diagonal
                    while(thickLine != 10){
                    image[dimx*p+Right-q  + thickLine].red = (23);
                    thickLine++;
                    }
                    thickLine = 0;
                    while(thickLine != 10){
                    image[dimx*p+Right-q + thickLine].green = (150);
                    thickLine++;
                    }
                    while(thickLine != 10){
                    image[dimx*p+Right-q + thickLine].blue = (45);
                    thickLine++;
                    }
                    q++;
                    
                }
          
            }
            //  'O'
            if (cur == 'O'){
                
                double r = (cell/2-2*width)+width;
                double xMid = (j*cell+width)/2 + (j*cell+cell-width)/2;
                double yMid = (i*cell+width)/2 + (i*cell+cell-width)/2;
                for (int p = i*cell+width; p < i*cell+cell-width; ++p) {
                    for (int l = j*cell+width; l < j*cell+cell-width; ++l) {
                        double d = pow(xMid-l,2) + pow(yMid-p,2);
                        d = sqrt(d);
                        d = abs(d-r);
                        if(d < 3){
                            image[dimx*p+l].red = (221);
                            image[dimx*p+l].green = (10);
                            image[dimx*p+l].blue = (50);
                        }
                    }
                }
            }
        
        }   
    }


///image processing///
    while(isExists(filename)) {
        ++num_pic;
        filename = "pic" + to_string(num_pic) + ".ppm";
    }
    ofstream imageFile(filename, ios::out | ios::binary);
    imageFile << "P6" << endl << dimx << " " << dimy << endl << 255 << endl;
  
    imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);
    imageFile.close();
    return filename;
}

int Board:: size() const{
    return Size;
}
 
//toString   
ostream& operator<< (ostream& os, const Board& b){
    int i, j; 
    for(i = 0; i < b.Size; i++){
        for(j = 0; j < b.Size; j++)
            os << b.board[i][j];
        os << endl;
    }
    return os;
}


