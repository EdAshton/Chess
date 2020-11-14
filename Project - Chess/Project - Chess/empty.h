//  empty.h
//  Project - Chess

#include <iostream>
#include "piece.h"
#include <vector>

#ifndef empty_h
#define empty_h

// Class for empty squares on the board
class empty: public piece
{
protected:
    int move_number;
public:
    empty() {}
    ~empty() {}
    void symbol()
    {
       std::cout << ' ';
    };
    char id()
    {
        char id;
        id = 'e';
        return id;
    };
    char colour()
    {
        char colour;
        colour = 'e';
        return colour;
    };
    int move_num(bool check_move)
    {
        return move_number;
    };
    bool move_check(int x_piece, int y_piece, int x_move, int y_move, std::vector<std::shared_ptr<piece>> vec, bool check_move_bool) {return false;}
};

#endif
