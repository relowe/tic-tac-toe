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

// This is a test program for the board class
#include <iostream>
#include "board.h"

using namespace std;

int main()
{
    char player;
    Tic_Tac_Toe_Board::Player human;
    Tic_Tac_Toe_Board::Player computer;
    Tic_Tac_Toe_Board::Player turn;
    Tic_Tac_Toe_Board board;
    int i;

    //get the player set up
    cout << "X or O? ";
    cin >> player;

    if(player == 'X') {
        human = Tic_Tac_Toe_Board::X;
        computer = Tic_Tac_Toe_Board::O;
    } else {
        human = Tic_Tac_Toe_Board::O;
        computer = Tic_Tac_Toe_Board::X;
    }

    //run all the turns
    turn = Tic_Tac_Toe_Board::X;
    while(board.winner() == Tic_Tac_Toe_Board::N) {
        if(turn==human) {
            turn = computer;
            do {
                cout << "i: ";
                cin >> i;
            } while(!board.move(human, i));
        } else {
            i = board.best_move(computer);
            cout << i << endl;
            board.move(computer, i);
            turn = human;
        }
    }
}
