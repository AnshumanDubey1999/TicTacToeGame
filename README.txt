====================================================================================================
                                           TIC - TAC - TOE
====================================================================================================

	This is a simple 3x3 Tic-Tac-Toe game with both single player and 2 player gameplay. The
single player mode also has 3 different levels of hardness. The Program takes input of name and a
single character symbol that represents the move a player has made. Each move is taken in input as
X and Y co-ordinate based on the table below : 

                                   (0,0)|(0,1)|(0,2)
                                   -----+-----+-----
                                   (1,0)|(1,1)|(1,2)
                                   -----+-----+-----
                                   (2,0)|(2,1)|(2,2)

	In single player mode, the computer uses 2 methods of choosing its move. For the easy level,
the computer randomly chooses the position of its move. For hard level, the computer choose a 
strategically sound position based on the current state of the board. Once the name and hardness 
level (in case of single player mode) has been set, the user/users can play the game for as many
turns as they want to.

----------------------------------------------------------------------------------------------------
Installation :
The folder comes with a .c file which needs to be compiled using a c compiler. Follow the following
steps to create the executable file.

  > Extract the .c file to a desired location.
  > Copy the address of the location where the .c file is kept.
  > Open the terminal and enter command cd followed by the location of the folder.
  > Enter the command "gcc TicTacToe.c -o <Desired File Name>".

An executable file of the desired name will be created at the location of the .c file.

----------------------------------------------------------------------------------------------------
Contact us at anshumandubey2k18@gmail.com for any further queries.