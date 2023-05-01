//  bishop.cpp
//  Project - Chess

#include <iostream>
#include "bishop.h"

void bishop::symbol()
{
    if(*team == 'W') std::cout << 'B';
    else std::cout << 'b';
};
char bishop::id() {
    char id;
    id = 'b';
    return id;
};
char bishop::colour()
{
    char colour;
    if(*team == 'W') colour = 'W';
    else colour = 'B';
    return colour;
}
int bishop::move_num(bool check_move)
{
    if (check_move == false) move_number += 1;
    return move_number;
};
bool bishop::move_check(int x_piece, int y_piece, int x_move, int y_move, std::vector<std::shared_ptr<piece>> vec, bool check_move)
{
    int x_change = x_move - x_piece, y_change = y_move - y_piece;
    bool valid_move{true};
    // If move coords ae the same as piece coords, return false
    if(abs(x_change) != abs(y_change)) return valid_move = false;
    // Cannot move in both x and y direction
    if(x_change > 0 && y_change > 0) {
        for(int i{1}; i < x_change; i++) {
            if(vec[(x_piece + i) + 8*(y_piece + i)] -> id() != 'e') return valid_move = false;
        }
    }
    else if(x_change < 0 && y_change > 0) {
        for(int i{1}; i < abs(x_change); i++) {
            if(vec[(x_piece - i) + 8*(y_piece + i)] -> id() != 'e') return valid_move = false;
        }
    }
    else if(x_change < 0 && y_change < 0) {
        for(int i{1}; i < abs(x_change); i++) {
            if(vec[(x_piece - i) + 8*(y_piece - i)] -> id() != 'e') return valid_move = false;
        }
    }
    else if(x_change > 0 && y_change < 0) {
        for(int i{1}; i < abs(x_change); i++) {
            if(vec[(x_piece + i) + 8*(y_piece - i)] -> id() != 'e') return valid_move = false;
        }
    }
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
}
