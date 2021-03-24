/*
* AUTHORS: <Tzion Beniaminov>
* Tests for notice Board
*/

#include "doctest.h"
#include "Board.hpp"
#include <string>
#include <algorithm>

using namespace std;
using namespace ariel;

TEST_CASE("Good tests for Post and Read functions") {
    Board board;
    
    board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "abcd");
    CHECK(board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/3) == ("_b_"));

    /*empty board case*/
    board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "____");
    CHECK(board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/4) == ("____"));

    /*overiding a post*/
    board.post(/*row=*/10, /*column=*/20, Direction::Horizontal, "aaaa");
    board.post(/*row=*/10, /*column=*/20, Direction::Horizontal, "bbbb");
    CHECK(board.read(/*row=*/10, /*column=*/20, Direction::Horizontal, /*length=*/4) == ("bbbb"));

    //edges of the board
    board.post(/*row=*/0, /*column=*/0, Direction::Horizontal, "xyz");
    CHECK(board.read(/*row=*/0, /*column=*/0, Direction::Horizontal, /*length=*/3) == ("xyz"));
    CHECK(board.read(/*row=*/0, /*column=*/0, Direction::Vertical, /*length=*/3) == ("x__"));
    CHECK(board.read(/*row=*/0, /*column=*/1, Direction::Vertical, /*length=*/3) == ("y__"));

    //random tests
    board.post(/*row=*/0, /*column=*/1, Direction::Vertical, "abc");
    CHECK(board.read(/*row=*/1, /*column=*/1, Direction::Horizontal, /*length=*/3) == ("b__"));
    CHECK(board.read(/*row=*/2, /*column=*/1, Direction::Horizontal, /*length=*/3) == ("c__"));

    board.post(/*row=*/5, /*column=*/2, Direction::Horizontal, "abcd abdc");
    CHECK(board.read(/*row=*/5, /*column=*/2, Direction::Vertical, /*length=*/3) == ("a__"));
    CHECK(board.read(/*row=*/5, /*column=*/3, Direction::Vertical, /*length=*/3) == ("b__"));
    CHECK(board.read(/*row=*/5, /*column=*/4, Direction::Vertical, /*length=*/3) == ("c_ "));
    CHECK(board.read(/*row=*/5, /*column=*/5, Direction::Vertical, /*length=*/3) == ("a__"));
    CHECK(board.read(/*row=*/5, /*column=*/6, Direction::Vertical, /*length=*/3) == (" __"));
    CHECK(board.read(/*row=*/5, /*column=*/7, Direction::Vertical, /*length=*/3) == ("a__"));
    CHECK(board.read(/*row=*/5, /*column=*/8, Direction::Vertical, /*length=*/3) == ("b__"));
    CHECK(board.read(/*row=*/5, /*column=*/9, Direction::Vertical, /*length=*/3) == ("d__"));
    CHECK(board.read(/*row=*/5, /*column=*/10, Direction::Vertical, /*length=*/3) == ("c__"));

    
    board.post(/*row=*/99, /*column=*/10, Direction::Horizontal, "cvvbn");
    CHECK(board.read(/*row=*/99, /*column=*/10, Direction::Vertical, /*length=*/1) == ("c"));
    CHECK(board.read(/*row=*/99, /*column=*/10, Direction::Vertical, /*length=*/1) == ("_"));
    CHECK(board.read(/*row=*/99, /*column=*/4, Direction::Vertical, /*length=*/3) == ("___"));

    board.post(/*row=*/20, /*column=*/20, Direction::Horizontal, "__");
    CHECK(board.read(/*row=*/20, /*column=*/20, Direction::Vertical, /*length=*/2) == ("__"));

}
