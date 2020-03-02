Phase 3 - Full Control and Integration
======================================
In this phase, we put all three pieces together!  

All of the action happens in the control layer. We have a singleton
global object (which we shouldn't do, but for this tutorial is ok),
and then we modify the callback so that it updates both ends of the
equation.

There is also a little bit of tweaking in the makefile.


Some Things to Try
==================
Now, here's a few things to try your hand at to practice FLTK
development.

  1. Ask the user if they want to be X or O and proceed based on their
     choice.
  2. Draw slashes through winners.
  3. Modify the AI so it sometimes messes up.
  4. Ask if the user wants to play again and then reset the game.
