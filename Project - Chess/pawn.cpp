//  pawn.cpp
//  Project - Chess

#include <iostream>
#include "pawn.h"

void pawn::symbol()
{
    if(*team == 'W') std::cout << 'P';
    else std::cout << 'i'; // i used for black pawns to differentiate from white pawns
};

char pawn::id()
{
    char id;
    id = 'p';
    return id;
};
char pawn::colour()
{
    char colour;
    if(*team == 'W') colour = 'W';
    else colour = 'B';
    return colour;
};
int pawn::move_num(bool check_move)
{
    return move_number;
};
bool pawn::move_check(int x_piece, int y_piece, int x_move, int y_move, std::vector<std::shared_ptr<piece> > vec, bool check_move)
{
    bool valid_move{true};
    // Rules for white
        if(vec[x_piece + 8*y_piece] -> colour() == 'W') {
        // Pawn can move two spaces forward on first move
            if(vec[x_piece + 8*y_piece] -> move_num(check_move) == 0) {
                if(y_move == y_piece + 1 || y_move == y_piece + 2) {
                    if(x_move == x_piece && vec[x_piece + 8*(y_piece + 1)] -> id() == 'e' && vec[x_move + 8*y_move] -> id() == 'e') {
                        if(check_move == false) move_number += 1;
                        return valid_move = true;
                    }
                }
            }
            else if(y_move == y_piece + 1) {
                if(x_move == x_piece && vec[x_move + 8*y_move] -> id() == 'e') return valid_move = true;
            }
            
            // Pawn can move diagonally forward to take an opposing piece
            if(x_move == x_piece + 1) {
                if(y_move == y_piece + 1) {
                    if(vec[x_piece + 8*y_piece] -> colour() != vec[x_move + 8*y_move] -> colour() && vec[x_move + 8*y_move] -> colour() != 'e') {
                        return valid_move = true;
                    }
                }
            }
            else if(x_move == x_piece - 1) {
                if(y_move == y_piece + 1) {
                    if(vec[x_piece + 8*y_piece] -> colour() != vec[x_move + 8*y_move] -> colour() && vec[x_move + 8*y_move] -> colour() != 'e') {
                        return valid_move = true;
                    }
                }
            }
        }
        
        // Rules for black - Y direction reversed
        else if(vec[x_piece + 8*y_piece] -> colour() == 'B') {
            if(vec[x_piece + 8*y_piece] -> move_num(check_move) == 0) {
                if(y_move == y_piece - 1 || y_move == y_piece - 2) {
                    if(x_move == x_piece && vec[x_piece + 8*(y_piece - 1)] -> id() == 'e' && vec[x_move + 8*y_move] -> id() == 'e') {
                        if(check_move == false) move_number += 1;
                        return valid_move = true;
                    }
                }
            }
            else if(y_move == y_piece - 1) {
                if(x_move == x_piece && vec[x_move + 8*y_move] -> id() == 'e') return valid_move = true;
            }

            // Pawn can move diagonally forward to take an opposing piece
            if(x_move == x_piece + 1) {
                if(y_move == y_piece - 1) {
                    if(vec[x_piece + 8*y_piece] -> colour() != vec[x_move + 8*y_move] -> colour() && vec[x_move + 8*y_move] -> colour() != 'e') {
                        return valid_move = true;
                    }
                }
            }
            else if(x_move == x_piece - 1) {
               if(y_move == y_piece - 1) {
                    if(vec[x_piece + 8*y_piece] -> colour() != vec[x_move + 8*y_move] -> colour() && vec[x_move + 8*y_move] -> colour() != 'e') {
                        return valid_move = true;
                    }
                }
            }
        }
    return valid_move = false;
}
