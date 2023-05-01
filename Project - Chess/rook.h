//  rook.h
//  Project - Chess

#include <iostream>
#include "piece.h"
#include <vector>

#ifndef rook_h
#define rook_h

class rook: public piece
{
protected:
    int move_number{0};
    const char *team;
public:
    rook(int n, const char* wb): move_number(n), team(wb) {}
    ~rook() {}
    void symbol();
    char id();
    int move_num(bool check_move);
    char colour();
    bool move_check(int x_piece, int y_piece, int x_move, int y_move, std::vector<std::shared_ptr<piece>> vec, bool check_move);
};

#endif
