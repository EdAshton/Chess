//  queen.cpp
//  Project - Chess

#include <iostream>
#include "queen.h"

void queen::symbol(){
    if(*team == 'W') std::cout << 'Q';
    else std::cout << 'q';
};
char queen::id() {
    char id;
    id = 'q';
    return id;
};
char queen::colour() {
    char colour;
    if(*team == 'W') colour = 'W';
    else colour = 'B';
    return colour;
}
int queen::move_num(bool check_move){
    if (check_move == false) move_number += 1;
    return move_number;
};
bool queen::move_check(int x_piece, int y_piece, int x_move, int y_move, std::vector<std::shared_ptr<piece>> vec, bool check_move)
{
    int x_change = x_move - x_piece, y_change = y_move - y_piece;
    bool valid_move{true};
    
    if(x_change == 0 && y_change == 0) return valid_move = false;
    
    // Queen rules are a combination of the bishop and rook rules i.e. can move along one axis or diagonally
    // Follow bishop rules
    if(abs(x_change) > 0 && abs(y_change) > 0) {
        if(abs(x_change) != abs(y_change)) return valid_move = false;
        
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
            for(int i{1}; i < abs(x_change); i++)
            {
                if(vec[(x_piece + i) + 8*(y_piece - i)] -> id() != 'e') return valid_move = false;
            }
        }
        if(vec[x_move + 8*y_move] -> id() == 'e') {
            return valid_move = true;
        }
        else if(vec[x_move + 8*y_move] -> colour() == vec[x_piece + 8*y_piece] -> colour()) {
            return valid_move == false;
        }
        else if(vec[x_move + 8*y_move] -> colour() != vec[x_piece + 8*y_piece] -> colour()) {
            return valid_move = true;
        }
    }
    
    // Follow rook rules
    else if(abs(x_change) == 0 || abs(y_change) == 0) {
        // Check x direction
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
    }
    return valid_move;
}
