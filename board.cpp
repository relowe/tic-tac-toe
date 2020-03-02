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
#include "board.h"

struct Move
{
    int index;
    int value; // -1 X wins, 0 draw/no win, +1 O wins
};

static Move minimax(Tic_Tac_Toe_Board board, Tic_Tac_Toe_Board::Player p) 
{
    Move best;                  //best index
    Tic_Tac_Toe_Board cand;     //candidate board 
    int cv;                     //candidate value

    //initialize best index to no move
    best.index=-1;

    //check the win conditions
    Tic_Tac_Toe_Board::Player w = board.winner();
    if(w == Tic_Tac_Toe_Board::D) {
        best.value=0;
        return best;
    } else if(w == Tic_Tac_Toe_Board::X) {
        best.value=-1;
        return best;
    } else if(w == Tic_Tac_Toe_Board::O) {
        best.value=1;
        return best;
    }

    //handle the move for O
    if(p == Tic_Tac_Toe_Board::O) {
        //maximize our result
        best.value = -2;
        for(int i=0; i<9; i++) {
            cand = board;
            if(!cand.move(p, i)) {
                continue;
            }
            cv = minimax(cand, Tic_Tac_Toe_Board::X).value;
            if(cv > best.value) {
                best.value = cv;
                best.index = i;
            }
        }
    } else {
        //maximize our result
        best.value = +2;
        for(int i=0; i<9; i++) {
            cand = board;
            if(!cand.move(p, i)) {
                continue;
            }
            cv = minimax(cand, Tic_Tac_Toe_Board::O).value;
            if(cv < best.value) {
                best.value = cv;
                best.index = i;
            }
        }
    }

    return best;
}

/////////////////////////
// constructors
/////////////////////////
Tic_Tac_Toe_Board::Tic_Tac_Toe_Board()
{
    //start with a blank board
    for(int i=0; i<9; i++) {
        board[i] = N;
    }
}


Tic_Tac_Toe_Board::Tic_Tac_Toe_Board(const Tic_Tac_Toe_Board& other)
{
    //copy the other's board
    for(int i=0; i<9; i++) {
        board[i] = other.board[i];
    }
}


// Returns the winner of the current board.  (Or N
// if there is not one.)
Tic_Tac_Toe_Board::Player Tic_Tac_Toe_Board::winner()
{
    int win_indexes[8][3] = {{0, 1, 2},
                             {3, 4, 5}, 
                             {6, 7, 8},
                             {0, 3, 6},
                             {1, 4, 7},
                             {2, 5, 8},
                             {0, 4, 8},
                             {2, 4, 6}};

    // go through each win condition
    for(int i=0; i<8; i++) {
        Player p = board[win_indexes[i][0]];

        if(p == N) {
            continue;
        }

        if(p == board[win_indexes[i][1]] && p == board[win_indexes[i][2]]) {
            return p;
        }
    }

    //full boards are a draw
    if(full()) {
        return D;
    }

    //return no winner
    return N;
}


// Returns the index of the optimal move for the player
int Tic_Tac_Toe_Board::best_move(Player p)
{
    //find the move
    Move m = minimax(*this, p);

    return m.index;
}


// Performs a move for the player on the given index
// returns false if the move is illegal
bool Tic_Tac_Toe_Board::move(Player p, int index)
{
    //non-blanks are illegal
    if(board[index] != N) {
        return false;
    }

    //make the move!
    board[index] = p;
    return true;
}


// Returns true if the board is full
bool Tic_Tac_Toe_Board::full()
{
    //look for an N
    for(int i=0; i<9; i++) {
        if(board[i] == N) {
            return false;
        }
    }

    //must be full!
    return true;
}
