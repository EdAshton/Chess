//  board.cpp
//  Project - Chess

#include <iostream>
#include "board.h"

// Fill vector for each piece/space in the board
void board::initialise_board()
{
    piece_vector.push_back(std::make_shared<rook>(0,&white));
    piece_vector.push_back(std::make_shared<knight>(0,&white));
    piece_vector.push_back(std::make_shared<bishop>(0,&white));
    piece_vector.push_back(std::make_shared<queen>(0,&white));
    piece_vector.push_back(std::make_shared<king>(0,&white));
    piece_vector.push_back(std::make_shared<bishop>(0,&white));
    piece_vector.push_back(std::make_shared<knight>(0,&white));
    piece_vector.push_back(std::make_shared<rook>(0,&white));
    for(int i{0}; i < 8; i++) {
        piece_vector.push_back(std::make_shared<pawn>(0,&white));
    };
    for(int i{2}; i < 6; i++) {
        for(int j{0}; j < 8; j++) {
            piece_vector.push_back(std::make_shared<empty>());
        };
    };
    for(int i{0}; i < 8; i++) {
        piece_vector.push_back(std::make_shared<pawn>(0,&black));
    };
    piece_vector.push_back(std::make_shared<rook>(0,&black));
    piece_vector.push_back(std::make_shared<knight>(0,&black));
    piece_vector.push_back(std::make_shared<bishop>(0,&black));
    piece_vector.push_back(std::make_shared<queen>(0,&black));
    piece_vector.push_back(std::make_shared<king>(0,&black));
    piece_vector.push_back(std::make_shared<bishop>(0,&black));
    piece_vector.push_back(std::make_shared<knight>(0,&black));
    piece_vector.push_back(std::make_shared<rook>(0,&black));
};

// Display up to date board to the player(s)
void board::print_board()
{
    std::cout << "\n  ---------------------------------" << std::endl;
    std::cout << "7";
    for(int i{56}; i < 64; i++) {
        std::cout << " | ";
        piece_vector[i] -> symbol();
    };
    std::cout << " |\n  ---------------------------------" << std::endl;
        
    std::cout << "6";
    for(int i{48}; i < 56; i++) {
        std::cout << " | ";
        piece_vector[i] -> symbol();
    };
    std::cout << " |\n  ---------------------------------" << std::endl;
          
    std::cout << "5";
    for(int i{40}; i < 48; i++) {
        std::cout << " | ";
        piece_vector[i] -> symbol();
    };
    std::cout << " |\n  ---------------------------------" << std::endl;
          
    std::cout << "4";
    for(int i{32}; i < 40; i++) {
        std::cout << " | ";
        piece_vector[i] -> symbol();
    };
    std::cout << " |\n  ---------------------------------" << std::endl;
          
    std::cout << "3";
    for(int i{24}; i < 32; i++) {
        std::cout << " | ";
        piece_vector[i] -> symbol();
    };
    std::cout << " |\n  ---------------------------------" << std::endl;
          
    std::cout << "2";
    for(int i{16}; i < 24; i++) {
        std::cout << " | ";
        piece_vector[i] -> symbol();
    };
    std::cout << " |\n  ---------------------------------" << std::endl;
          
    std::cout << "1";
    for(int i{8}; i < 16; i++) {
        std::cout << " | ";
        piece_vector[i] -> symbol();
    };
    std::cout << " |\n  ---------------------------------" << std::endl;
          
    std::cout << "0";
    for(int i{0}; i < 8; i++) {
        std::cout << " | ";
        piece_vector[i] -> symbol();
    };
    std::cout << " |\n  ---------------------------------" << std::endl;
        
    std::cout << "    0   1   2   3   4   5   6   7" << std::endl;
};

// Store all past moves in move vector as strings
void board::store_moves(int x_piece, int y_piece, int x_move, int y_move)
{
    std::stringstream piece;
    std::string piece_string;
    if(piece_vector[x_piece + 8*y_piece] -> colour() == 'W') {
        piece << piece_vector[x_piece + 8*y_piece] -> id();
        piece << x_piece;
        piece << y_piece;
        piece << "->";
        piece << x_move;
        piece << y_move;
        piece >> piece_string;
        move_vector.push_back(piece_string);
    }
    else if(piece_vector[x_piece + 8*y_piece] -> colour() == 'B') {
        piece << piece_vector[x_piece + 8*y_piece] -> id();
        piece << x_piece;
        piece << y_piece;
        piece << "->";
        piece << x_move;
        piece << y_move;
        piece >> piece_string;
        move_vector.push_back(piece_string);
    }
}

// Print past moves to screen using move vector
void board::print_moves()
{
    std::cout << "\n  White  |  Black" << std::endl;
    std::cout << "-------------------" << std::endl;
    for(int i = 0; i <= move_counter; i++) {
        if(i % 2 == 0) {
            std::cout << " " << move_vector[i] << " | ";
        }
        else {
            std::cout << move_vector[i] << std::endl;
        }
    }
};

// Function to check if a move is valid
bool board::check_move(std::string move)
{
    bool valid_move{false};
    bool check_move_bool{false};
    
    // Allocates coordinate of chosen piece and move, and checks input is formatted correctly
    if(move.length() != 8 && move.length() != 2) return valid_move = false;
    
    if(move[0] == '0') x_piece = 0;
    else if(move[0] == '1') x_piece = 1;
    else if(move[0] == '2') x_piece = 2;
    else if(move[0] == '3') x_piece = 3;
    else if(move[0] == '4') x_piece = 4;
    else if(move[0] == '5') x_piece = 5;
    else if(move[0] == '6') x_piece = 6;
    else if(move[0] == '7') x_piece = 7;
    else return valid_move = false;
    
    if(move[1] == '0') y_piece = 0;
    else if(move[1] == '1') y_piece = 1;
    else if(move[1] == '2') y_piece = 2;
    else if(move[1] == '3') y_piece = 3;
    else if(move[1] == '4') y_piece = 4;
    else if(move[1] == '5') y_piece = 5;
    else if(move[1] == '6') y_piece = 6;
    else if(move[1] == '7') y_piece = 7;
    else return valid_move = false;
    
    switch(move.length()) {
        // Case 2 is if the user wants to see allowed moves for a piece
        case 2:
            if(move_counter % 2 == 0 && piece_vector[x_piece + 8*y_piece] -> colour() != 'W') return valid_move = false;
            if(move_counter % 2 != 0 && piece_vector[x_piece + 8*y_piece] -> colour() != 'B') return valid_move = false;
            allowed_moves(x_piece, y_piece);
            valid_move = true;
            break;
            
        // Default if user is making a move
        default:
            if(move[6] == '0') x_move = 0;
            else if(move[6] == '1') x_move = 1;
            else if(move[6] == '2') x_move = 2;
            else if(move[6] == '3') x_move = 3;
            else if(move[6] == '4') x_move = 4;
            else if(move[6] == '5') x_move = 5;
            else if(move[6] == '6') x_move = 6;
            else if(move[6] == '7') x_move = 7;
            else return valid_move = false;
    
            if(move[7] == '0') y_move = 0;
            else if(move[7] == '1') y_move = 1;
            else if(move[7] == '2') y_move = 2;
            else if(move[7] == '3') y_move = 3;
            else if(move[7] == '4') y_move = 4;
            else if(move[7] == '5') y_move = 5;
            else if(move[7] == '6') y_move = 6;
            else if(move[7] == '7') y_move = 7;
            else return valid_move = false;
    
            if(move[2] != ' ') return valid_move = false;
            if(move[3] != 't') return valid_move = false;
            if(move[4] != 'o') return valid_move = false;
            if(move[5] != ' ') return valid_move = false;
    
            // Checks user has not selected an empty square to move
            if(piece_vector[x_piece + 8*y_piece] -> id() == 'e') {
                std::cout << "Empty square chosen" << std::endl;
                return valid_move = false;
            };
            
            // Check user is choosing the correct colour
            if(move_counter % 2 == 0 && piece_vector[x_piece + 8*y_piece] -> colour() != 'W') return valid_move = false;
            if(move_counter % 2 != 0 && piece_vector[x_piece + 8*y_piece] -> colour() != 'B') return valid_move = false;
            
            // Check user has not input the pieces coorinate as its move location
            if(x_piece == x_move && y_piece == y_move) return valid_move = false;
    
            // Check move - send move to given pieces class
            if(piece_vector[x_piece + 8*y_piece] -> move_check(x_piece, y_piece, x_move, y_move, piece_vector, check_move_bool) == true) {
                if(piece_vector[x_piece + 8*y_piece] -> colour() != piece_vector[x_move + 8*y_move] -> colour() && piece_vector[x_move + 8*y_move] -> colour() != 'e') {
                    if(piece_vector[x_piece + 8*y_piece] -> colour() == 'W') std::cout << "Black piece taken!" << std::endl;
                    if(piece_vector[x_piece + 8*y_piece] -> colour() == 'B') std::cout << "White piece taken!" << std::endl;
                    piece_taken(x_move, y_move);
                }
                valid_move = true;
            }
            else valid_move = false;
            
            if(valid_move == true) {
                store_moves(x_piece, y_piece, x_move, y_move);
            }
        }
    // Promotion of pawn
    if(piece_vector[x_piece + 8*y_piece] -> id() == 'p') {
        promotion(x_piece, y_piece);
    }
    
    return valid_move;
};

void board::piece_taken(int x , int y)
{
    piece_vector.erase(piece_vector.begin() + (x + 8*y));
    piece_vector.emplace(piece_vector.begin() + (x + 8*y), std::make_shared<empty>());
}

// Print allowed moves for a specified piece
void board::allowed_moves(int x, int y)
{
    int allowed_int{0};
    std::cout << "Allowed moves: ";
    for(int i{0}; i < 8; i++){
        for(int j{0}; j < 8; j++) {
            bool check_move_bool{true};
            if(piece_vector[x + 8*y] -> move_check(x, y, i, j, piece_vector, check_move_bool) == true) {
                allowed_int += 1;
                std::cout << i << j << " ";
            }
        }
    }
    if(allowed_int == 0) std::cout << "None";
    std::cout << std::endl;
}

// Pawn is promoted if reaching the other side of the board
void board::promotion(int x_piece, int y_piece)
{
    std::string chosen_piece;
    if(piece_vector[x_piece + 8*y_piece] -> colour() == 'W') {
        if(y_move == 7) {
            std::cout << "Pawn promoted! What piece would you like to promote the pawn too?" << std::endl;
            std::cout << "Type queen, rook, bishop or knight: ";
            std::getline (std::cin,chosen_piece);
            while(chosen_piece != "queen" && chosen_piece != "rook" && chosen_piece != "bishop" && chosen_piece != "knight") {
                std::cout << "Invalid Input, try again: ";
                std::getline (std::cin,chosen_piece);
            }
            if(chosen_piece == "queen") {
                piece_vector.erase(piece_vector.begin() + (x_piece + 8*y_piece));
                piece_vector.emplace(piece_vector.begin() + (x_piece + 8*y_piece), std::make_shared<queen>(0, &white));
                std::cout << "\nPawn promoted to queen" << std::endl;
            }
            if(chosen_piece == "rook") {
                piece_vector.erase(piece_vector.begin() + (x_piece + 8*y_piece));
                piece_vector.emplace(piece_vector.begin() + (x_piece + 8*y_piece), std::make_shared<rook>(0, &white));
                std::cout << "\nPawn promoted to rook" << std::endl;
            }
            if(chosen_piece == "bishop") {
                piece_vector.erase(piece_vector.begin() + (x_piece + 8*y_piece));
                piece_vector.emplace(piece_vector.begin() + (x_piece + 8*y_piece), std::make_shared<bishop>(0, &white));
                std::cout << "\nPawn promoted to bishop" << std::endl;
            }
            if(chosen_piece == "knight") {
                piece_vector.erase(piece_vector.begin() + (x_piece + 8*y_piece));
                piece_vector.emplace(piece_vector.begin() + (x_piece + 8*y_piece), std::make_shared<knight>(0, &white));
                std::cout << "\nPawn promoted to knight" << std::endl;
            }
        }
    }
    else {
       if(y_move == 0) {
            std::cout << "Pawn promoted! What piece would you like to promote the pawn too?" << std::endl;
            std::cout << "Type queen, rook, bishop or knight: ";
            std::getline (std::cin,chosen_piece);
            while(chosen_piece != "queen" && chosen_piece != "rook" && chosen_piece != "bishop" && chosen_piece != "knight") {
                std::cout << "Invalid Input, try again: ";
                std::getline (std::cin,chosen_piece);
            }
            if(chosen_piece == "queen") {
                piece_vector.erase(piece_vector.begin() + (x_piece + 8*y_piece));
                piece_vector.emplace(piece_vector.begin() + (x_piece + 8*y_piece), std::make_shared<queen>(0, &black));
                std::cout << "\nPawn promoted to queen" << std::endl;
            }
            if(chosen_piece == "rook") {
                piece_vector.erase(piece_vector.begin() + (x_piece + 8*y_piece));
                piece_vector.emplace(piece_vector.begin() + (x_piece + 8*y_piece), std::make_shared<rook>(0, &black));
                std::cout << "\nPawn promoted to rook" << std::endl;
            }
            if(chosen_piece == "bishop") {
                piece_vector.erase(piece_vector.begin() + (x_piece + 8*y_piece));
                piece_vector.emplace(piece_vector.begin() + (x_piece + 8*y_piece), std::make_shared<bishop>(0, &black));
                std::cout << "\nPawn promoted to bishop" << std::endl;
            }
            if(chosen_piece == "knight") {
                piece_vector.erase(piece_vector.begin() + (x_piece + 8*y_piece));
                piece_vector.emplace(piece_vector.begin() + (x_piece + 8*y_piece), std::make_shared<knight>(0, &black));
                std::cout << "\nPawn promoted to knight" << std::endl;
            }
        }
    }
}

// Check and checkmate
bool board::check()
{
    bool check_move_bool{true};
    bool in_check_w{false}, in_check_b{false};
    bool checkmate{false};
    bool w_king_taken{true}, b_king_taken{true};
    
    // Find coordinates of both kings
    int w_king_x{0}, w_king_y{0}, b_king_x{0}, b_king_y{0};
    for(int i{0}; i < 8; i++) {
        for(int j{0}; j < 8; j++) {
            if(piece_vector[i + 8*j] -> id() == 'k' && piece_vector[i + 8*j] -> colour() == 'W') {
                w_king_x = i;
                w_king_y = j;
                w_king_taken = false;
            }
            if(piece_vector[i + 8*j] -> id() == 'k' && piece_vector[i + 8*j] -> colour() == 'B') {
                b_king_x = i;
                b_king_y = j;
                b_king_taken = false;
            }
        }
    }
    
    // If either king has been taken, announce winner
    if(w_king_taken == true) {
        std::cout << "Checkmate! Black wins!" << std::endl;
        return checkmate = true;
    }
    if(b_king_taken == true) {
        std::cout << "Checkmate! White wins!" << std::endl;
        return checkmate = true;
    }
    
    // For every piece, check if it can take a king
    for(int i{0}; i < 8; i++) {
        for(int j{0}; j < 8; j++) {
            if(piece_vector[i + 8*j] -> move_check(i, j, w_king_x, w_king_y, piece_vector, check_move_bool) == true) {
                in_check_w = true;
            }
            if(piece_vector[i + 8*j] -> move_check(i, j, b_king_x, b_king_y, piece_vector, check_move_bool) == true) {
                in_check_b = true;
            }
        }
    }
    
    // If the king cant move, checkmate
    if(in_check_w == true) {
        for(int i{0}; i < 8; i++) {
            for(int j{0}; j < 8; j++) {
                if(piece_vector[w_king_x + 8*w_king_y] -> move_check(w_king_x, w_king_y, i, j, piece_vector, check_move_bool) == true && piece_vector[i+8*j] -> colour() != 'W') {
                    std:: cout << "Check!" << std::endl;
                    return checkmate = false;
                }
            }
        }
        std::cout << "Checkmate! Black wins!" << std::endl;
        return checkmate = true;
    }
    if(in_check_b == true) {
        for(int i{0}; i < 8; i++) {
            for(int j{0}; j < 8; j++) {
                if(piece_vector[b_king_x + 8*b_king_y] -> move_check(b_king_x, b_king_y, i, j, piece_vector, check_move_bool) == true && piece_vector[i+8*j] -> colour() != 'B') {
                    std:: cout << "Check!" << std::endl;
                    return checkmate = false;
                }
            }
        }
        std::cout << "Checkmate! White wins!" << std::endl;
        return checkmate = true;
    }
    return checkmate;
}
