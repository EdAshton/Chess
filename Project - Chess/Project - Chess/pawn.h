//  pawn.h
//  Project - Chess

#include <iostream>
#include "piece.h"
#include <vector>

#ifndef pawn_h
#define pawn_h

class pawn: public piece
{
protected:
    int move_number;
    const char *team;
public:
    pawn(int n, const char* wb): move_number(n), team(wb) {}
    ~pawn() {}
    void symbol();
    char id();
    int move_num(bool check_move);
    char colour();
    bool move_check(int x_piece, int y_piece, int x_move, int y_move, std::vector<std::shared_ptr<piece>> vec, bool check_move);
};

#endif

