//  board.h
//  Project - Chess

#include <string>
#include <sstream>
#include <vector>
#include "piece.h"
#include "empty.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

#ifndef board_h
#define board_h

class board
{
private:
    const char white = 'W';
    const char black = 'B';
    const char blank = ' ';
public:
    std::vector<std::shared_ptr<piece>> piece_vector;
    std::vector<std::string> move_vector;
    int move_counter{0};    // Number of times a given piece has been moved
    int x_piece, y_piece;   // Coordinates of chosen piece
    int x_move, y_move;     // Coordinates of chosen move
    void initialise_board();
    void print_board();
    void store_moves(int x, int y, int a, int b);
    void print_moves();
    bool check_move(std::string move);
    void piece_taken(int x, int y);
    void allowed_moves(int x, int y);
    void promotion(int x_piece, int y_piece);
    bool check();
     ~board() {}
};
#endif
