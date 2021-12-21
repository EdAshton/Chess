//  knight.h
//  Project - Chess

#include <iostream>
#include "piece.h"
#include <vector>

#ifndef knight_h
#define knight_h

class knight: public piece
{
protected:
    int move_number;
    const char *team;
public:
    knight(int n, const char* wb): move_number(n), team(wb) {}
    ~knight() {}
    void symbol();
    char id();
    int move_num(bool check_move);
    char colour();
    bool move_check(int x_piece, int y_piece, int x_move, int y_move, std::vector<std::shared_ptr<piece>> vec, bool check_move);
};

#endif
