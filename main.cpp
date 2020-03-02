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
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include "tic-tac-toe.h"
#include "control.h"


int main(int argc, char **argv)
{
    Fl_Double_Window *window;

    // create the window
    window = make_window();

    // set up the callbacks
    register_square_callbacks();

    // show the window
    window->show(argc, argv);

    //run the event loop
    return Fl::run();
}
