//  This is a an implementation of Tic-Tac-Toe using FLTK.
//  Copyright (C) 2020 Robert Lowe
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.


//  This file contains the definition of a class which represents
//  a tic-tac-toe board.  It also has a function that will return the
//  next optimal move for a player.
// 
//  Optimal moves are computed using the minimax algorithm.
//
//  The tic-toe-board is laid out in a single dimensional array
//  with the following configuration
//      0 | 1 | 2
//     ---+---+---
//      3 | 4 | 5
//     ---+---+---
//      6 | 7 | 8
//  Moves are input and reported using these numbers.
#ifndef BOARD_H
#define BOARD_H

class Tic_Tac_Toe_Board 
{
public:
    //constructors
    Tic_Tac_Toe_Board();
    Tic_Tac_Toe_Board(const Tic_Tac_Toe_Board& other);

    //an internal type representing the players/outcome
    //  X - The X player
    //  O - The O player
    //  D - The Draw player (for outcomes)
    //  N - For no winner and/or no one on square
    enum Player { X, O, D, N};


    // Returns the winner of the current board.  (Or N
    // if there is not one.)
    Player winner();

    // Returns the index of the optimal move for the player
    int best_move(Player p);

    // Performs a move for the player on the given index
    // returns false if the move is illegal
    bool move(Player p, int index);

    // Returns true if the board is full
    bool full();
private:
    Player board[9];    // The actual board
};


#endif
