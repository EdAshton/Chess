//  king.h
//  Project - Chess

#include <iostream>
#include "piece.h"
#include <vector>

#ifndef king_h
#define king_h

class king: public piece
{
protected:
    int move_number;
    const char *team;
public:
    king(int n, const char* wb): move_number(n), team(wb) {}
    ~king() {}
    void symbol();
    char id();
    int move_num(bool check_move);
    char colour();
    bool move_check(int x_piece, int y_piece, int x_move, int y_move, std::vector<std::shared_ptr<piece>> vec, bool check_move);
};


#endif
