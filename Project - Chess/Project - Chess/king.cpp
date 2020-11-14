//  king.cpp
//  Project - Chess

#include <iostream>
#include "king.h"

void king::symbol() {
    if(*team == 'W') std::cout << 'K';
    else std::cout << 'k';
};
char king::id() {
    char id;
    id = 'k';
    return id;
};
char king::colour() {
    char colour;
    if(*team == 'W') colour = 'W';
    else colour = 'B';
    return colour;
}
int king::move_num(bool check_move){
    if (check_move == false) move_number += 1;
    return move_number;
};
bool king::move_check(int x_piece, int y_piece, int x_move, int y_move, std::vector<std::shared_ptr<piece>> vec, bool check_move)
{
    bool valid_move{true};
    int x_change = x_move - x_piece, y_change = y_move - y_piece;
    // If move coords and piece coords are the same, return false
    if(x_change == 0 && y_change == 0) return valid_move = false;
    // Cannot move greater than one space in either axis
    if(abs(x_change) > 1 || abs(y_change) > 1) return valid_move = false;
    // Check move spot is not taken by a piece of the same colour
    if(vec[x_move + 8*y_move] -> id() == 'e') return valid_move = true;
    if(vec[x_move + 8*y_move] -> colour() != vec[x_piece + 8*y_piece] -> colour()) {
        return valid_move = true;
    }
    else return valid_move = false;
}
