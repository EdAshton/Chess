//  knight.cpp
//  Project - Chess

#include <iostream>
#include "knight.h"

void knight::symbol()
{
    if(*team == 'W') std::cout << 'N'; // K used for king, so knight labelled with N
    else std::cout << 'n';
};
char knight::id()
{
    char id;
    id = 'n'; 
    return id;
};
char knight::colour()
{
    char colour;
    if(*team == 'W') colour = 'W';
    else colour = 'B';
    return colour;
};
int knight::move_num(bool check_move)
{
    if (check_move == false) move_number += 1;
    return move_number;
};
bool knight::move_check(int x_piece, int y_piece, int x_move, int y_move, std::vector<std::shared_ptr<piece> > vec, bool check_move)
{
    int x_change = x_move - x_piece, y_change = y_move - y_piece;
    bool valid_move{true};
    // Can move at most 2 spaces in either axis
    if(abs(x_change) > 2 || abs(x_change) == 0) return valid_move = false;
    if(abs(y_change) > 2 || abs(y_change) == 0) return valid_move = false;
    if(abs(x_change) == abs(y_change)) return valid_move = false;
    // Check move spot is not taken by a piece of the same colour
    if(vec[x_move + 8*y_move] -> id() == 'e') {
        return valid_move = true;
    }
    else if(vec[x_move + 8*y_move] -> colour() == vec[x_piece + 8*y_piece] -> colour()) {
        return valid_move == false;
    }
    else if(vec[x_move + 8*y_move] -> colour() != vec[x_piece + 8*y_piece] -> colour()) {
        return valid_move = true;
    }
    return valid_move;
};
