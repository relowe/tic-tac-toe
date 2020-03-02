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
#include <Fl/Fl.H>
#include <Fl/Fl_Button.H>
#include "tic-tac-toe.h"
#include "control.h"
#include "board.h"

// An array of button pointers for easy access
static Fl_Button* cell[9];

// The state of the Tic-Tac-Toe board
static Tic_Tac_Toe_Board board;


// The square callback function (which is only used in the controller)
static void square_callback(Fl_Button *button)
{
    //make the player move
    button->label("X");
    button->callback((Fl_Callback*)nullptr);

    //log the player move 
    board.move(Tic_Tac_Toe_Board::X, (int)((long)button->user_data()));

    //make the computer move in the backend
    int i= board.best_move(Tic_Tac_Toe_Board::O);
    if(i >= 0) {
        board.move(Tic_Tac_Toe_Board::O, i);

        //make the computer move in the GUI
        cell[i]->label("O");
        cell[i]->callback((Fl_Callback*) nullptr);
    }

    //log winners
    Tic_Tac_Toe_Board::Player w = board.winner();
    if(w == Tic_Tac_Toe_Board::O) {
        message->value("I Win!");
    } else if(w == Tic_Tac_Toe_Board::X) {
        message->value("You Win!");
    } else if(w == Tic_Tac_Toe_Board::D) {
        message->value("Draw");
    }
}


// This function registers the callback functions for each square
void register_square_callbacks()
{
    // set up the button pointers
    cell[0] = btn0;
    cell[1] = btn1;
    cell[2] = btn2;
    cell[3] = btn3;
    cell[4] = btn4;
    cell[5] = btn5;
    cell[6] = btn6;
    cell[7] = btn7;
    cell[8] = btn8;

    // go through each button and set the callback
    for(int i=0; i < 9; i++) {
        cell[i]->callback((Fl_Callback*) square_callback);
    }
}
