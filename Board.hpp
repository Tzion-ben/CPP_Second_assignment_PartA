#pragma once

#include<iostream>
#include <string>
#include <vector>
#include "Direction.hpp"


namespace ariel{
    class Board{
        public:

            /*empty constractor*/
            Board ();
            /*temp prametries constractor*/
            Board (unsigned int rows , unsigned int columns);

            void post(unsigned int row, unsigned int column, Direction direction, std::string toPost);
            std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int postLength);
            void show();

        private :
            char ** _noticeBoard;
            // std::vector<std::vector<char>> noticeBoard ;
    };
}