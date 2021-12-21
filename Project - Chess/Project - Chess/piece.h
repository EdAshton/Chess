//  piece.h
//  Project - Chess

#ifndef piece_h
#define piece_h

// Polymorphic base class for all pieces (including empty squares) on the board
class piece
{
public:
    virtual ~piece(){}
    virtual void symbol() = 0;
    virtual char id() = 0;
    virtual char colour() = 0;
    virtual int move_num(bool check_move) = 0;
    virtual bool move_check(int x_piece, int y_piece, int x_move, int y_move, std::vector<std::shared_ptr<piece>> vec, bool check_move) = 0;
};

#endif 

