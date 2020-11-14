// OOP in C++ project
// Edward Ashton 9914839
// Board game - chess
// Code is split into two main classes, board and piece. All piece types are derived classes of piece
// Main game loop is play_game(). Creates an instance of board called game.
// To enter a move, use the form 36 to 45
// To check allowed moves, enter coordinates of the piece which you would like to check

#include <iostream>
#include "board.h"

bool play_game(){
    std::string chosen_move;
    board game;
    std::cout << "White is upper case. Black is lower case." << std::endl;
    std::cout << "To see allowed moves for a piece, enter its coordinates (e.g. 25)" << std::endl;
    game.initialise_board();
    game.print_board();
    // Main game loop
    while(true) {
        // Checks if it is white or blacks turn, and obtains input from user
        if(game.move_counter % 2 == 0) {
            std::cout << "White, enter your chosen move (i.e. ab to xy): ";
        }
        else {
            std::cout << "Black, enter your chosen move (i.e. ab to xy): ";
        };
        
        std::getline (std::cin,chosen_move);
        
        // Check move is valid
        while(game.check_move(chosen_move) == false) {
            std::cout << "Invalid input" << std::endl;
            std::cout << "Enter your chosen move (e.g. ab to xy): ";
            std::getline (std::cin,chosen_move);
        };
        // If move is valid, move the piece
        if(chosen_move.length() != 2) {
            std::swap(game.piece_vector[game.x_piece + 8*game.y_piece], game.piece_vector[game.x_move + 8*game.y_move]);
            game.print_moves();
            game.print_board();
            // Check if either king is in check
            if(game.check() == true){
                return false;
            }
            // Move counter to determine if it is white or blacks turn
            game.move_counter += 1;
        }
    }
};

int main()
{
    std::string response{"y"};
    
    // Loop that asks if the user wishses to play a new game after finishing
    while(response == "y"){
        play_game();
        std::cout << "Would you like to play again? (y/n): ";
        std::getline (std::cin,response);
        while(response != "y" && response != "n"){
            std::cout << "Invalide input. Would you like to play again? (y/n): ";
            std::getline (std::cin,response);
        }
    }
}
