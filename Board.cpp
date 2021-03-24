#include <iostream>
#include <string>
#include "Direction.hpp"
#include "Board.hpp"


using namespace std;
using namespace ariel;

const int TEMP_ROWS = 300; 
const int TEMP_COLUMNS = 400;

/*outLine empty constractor*/
Board :: Board (){
    _noticeBoard = new char*[TEMP_ROWS];
    for(int i=0 ; i<TEMP_ROWS ; i++){
        _noticeBoard [i] = new char [TEMP_COLUMNS];
    }
}

/*outLine prametries constractor*/
Board :: Board (unsigned int rows , unsigned int columns){
    _noticeBoard = new char*[rows];
    for(int i=0 ; i<rows ; i++){
        _noticeBoard[i] = new char [columns];
    }
}

/*outLine implementation to Board class*/
void Board :: post(unsigned int row, unsigned int column, Direction direction, string toPost){
    cout << "Post !!" << endl;
    }
string Board :: read(unsigned int row, unsigned int column, Direction direction, unsigned int postLength){
    string strTemp;
    strTemp+= this->_noticeBoard [0][0];
    return strTemp;
    }
void Board :: show(){
//    cout << this->_noticeBoard [0][0] << endl;
    cout << "SHOW !!" << endl;
    }