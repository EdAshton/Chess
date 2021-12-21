//  rook.cpp
//  Project - Chess

#include <iostream>
#include "rook.h"

void rook::symbol()
{
    if(*team == 'W') std::cout << 'R';
    else std::cout << 'r';
};

char rook::id()
{
    char id;
    id = 'r';
    return id;
};
char rook::colour()
{
    char colour;
    if(*team == 'W') colour = 'W';
    else colour = 'B';
    return colour;
};
int rook::move_num(bool check_move)
{
    if (check_move == false) move_number += 1;
    return move_number;
};
bool rook::move_check(int x_piece, int y_piece, int x_move, int y_move, std::vector<std::shared_ptr<piece> > vec, bool check_move)
{
    bool valid_move{true};
    // If move coords same as piece coords, return false
    if(x_move == x_piece && y_move == y_piece) return valid_move = false;
    // Check rules for x direction
    // Moving right
    if(x_piece < x_move) {
        if(y_piece != y_move) return valid_move = false;
        for(int i{x_piece + 1}; i < x_move; i++) {
            if(vec[i + 8*y_piece] -> id() != 'e') return valid_move = false;
        }
        if(vec[x_move + 8*y_move] -> id() != 'e') {
            if(vec[x_move + 8*y_move] -> colour() != vec[x_piece + 8*y_piece] -> colour()) {
                return valid_move = true;
            }
            else return valid_move = false;
        }
    }
    // Moving left
    else if(x_piece > x_move) {
        if(y_piece != y_move) return valid_move = false;
        for(int i{x_move+1}; i < x_piece; i++) {
            if(vec[i + 8*y_piece] -> id() != 'e') return valid_move = false;
        }
        if(vec[x_move + 8*y_move] -> id() !='e') {
            if(vec[x_move + 8*y_move] -> colour() != vec[x_piece + 8*y_piece] -> colour()) {
                return valid_move = true;
            }
            else return valid_move = false;
        }
    }
    
    // Check rules for y direction
    // Moving up
    if(y_move > y_piece) {
        if(x_move != x_piece) return valid_move = false;
        for(int i{y_piece + 1}; i < y_move; i++) {
            if(vec[x_piece + 8*i] -> id() != 'e') return valid_move = false;
        }
        if(vec[x_move + 8*y_move] -> id() != 'e') {
            if(vec[x_move + 8*y_move] -> colour() != vec[x_piece + 8*y_piece] -> colour()) {
                return valid_move = true;
            }
            else return valid_move = false;
        }
    }
    // Moving down
    else if(y_move < y_piece) {
        if(x_move != x_piece) return valid_move = false;
        for(int i{y_move + 1}; i < y_piece; i++) {
            if(vec[x_piece + 8*i] -> id() != 'e') return valid_move = false;
        }
        if(vec[x_move + 8*y_move] -> id() != 'e') {
            if(vec[x_move + 8*y_move] -> colour() != vec[x_piece + 8*y_piece] -> colour()) {
                return valid_move = true;
            }
            else return valid_move = false;
        }
    }
    return valid_move;
};
