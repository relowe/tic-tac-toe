Tic-Tac-Toe
===========
This repository contains a simple tic-tac-toe game.  The purpose of
this is to serve as an FLTK code example.

In this version of the program, we will be coding a singleton window
which uses a collection of global variables to control the window.
This is, of course, not ideal.  We will use a backend object to
control the business logic of the tic tac toe program. This
application can be thought of as consisting of three layers:

  1. Model - Backend Business Logic
  2. View - The GUI classes
  3. Control - Callbacks and main function

In order to make this tutorial an aid in transition from procedural to
object oriented programming, the View and Control are written in
a procedural way.  The drawback of this is that, owing to the way
fluid will construct the FLTK cxx code, we can really only expect to
make one Tic-Tac-Toe board per application.  This will be ok, but
a full OOP model would be preferable. (We'll see this in another
tutorial!)

The Model layer will include an object, which we will associate with
the callbacks, and it will maintain the state and logic of the
tic-tac-toe board.


Following Along With Development
================================
Because this program is intended to be an example/tutorial of FLTK
development, it will be set up with tags to allow you to see how the
program develops over time. You can observe the tags on GitHub, so you
can see what was added/changed at each phase of development.

The phases are as follows:

  * phase-0: The initial version of the repository
  * phase-1: Construction of the GUI and basic controller
  * phase-2: Creation and test of the tic-tac-toe model
  * phase-3: Setting up the controller to use the model 

phase-3 is the final tag, and is therefore also equivalent to the HEAD
of the master branch.


Checking Out Tags in git
========================
You have two options for following the tutorial.  First, you could use
the GUI on GitHub.  Second, you could clone the repository and
checkout each tag.  This section covers how to navigate the phases
from the git command line client.

When you clone the repository, you will get the master version (which
contains the completed program).  So long as you did not tell it not
fetch tags, git clone will download the tags.  You can list them using
the following command:

```bash
git tag -l
```

If you don't see the tags, you can fetch them with:
```bash
git fetch --tags
```

From there, you can checkout a tag:
```bash
git checkout tags/<tag-name>
```

For example, the checkout phase-0, do the following:
```bash
git checkout tags/phase-0
```
This will rollback your repository to the state the files were in at
this point.  You can then investigate the code and read the phase
notes.

When you are done, you can move on to other phases, so you can see
what has changed in this phase.  It should be noted that when you do
this, it will put you into a state called "detached HEAD mode" which
means you cannot commit changes to the repository without starting
a branch.  To get back on the main branch, just execute the following:
```bash
git checkout master
```
From there, git will behave like normal.

If you want to play around with code at various tags, you can always
check them out into a new branch and have at it!
```bash
git checkout tags/<tag-name> -b <branch>
```


Phase Notes
===========
The directory notes/ contains a series of md files with notes about
what each phase contains.  These notes will appear with their
respective phases, so be sure to take a look at these files every time
you change the tag.  (The master includes all of these notes.)

License 
=======
This program and all accompanying documentation is distributed under
the terms of the GPL v3 license.  See the LICENSE file for more
details.
