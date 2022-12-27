Word Game

This is a simple word game in which the player(s) try to guess a randomly selected sentence. The game has the option of 2 players and includes features such as coloring the words green if they exist in the sentence and are in the correct position, coloring the words red if they exist in the sentence but are not in the correct position, and calculating the score.

How to run the game

To run the game, compile the source files and run the resulting executable file.

File structure

The code for the game is split into the following source and header files:


words.h: Contains the definitions for the Word and Sentence structs and the readSentence and checkWord functions.
words.c: Contains the implementations of the readSentence and checkWord functions.
app.h: Contains the definition for the Game struct and the initGame and playRound functions.
app.c: Contains the implementations of the initGame and playRound functions.
main.c: Contains the main function that runs the game.
menu.h: Contains the definition for the displayMenu function.
menu.c: Contains the implementation of the displayMenu function.

Dependencies

The game depends on the following standard library header files:

stdio.h: For input/output operations.
string.h: For string manipulation functions.
time.h: For the time and srand functions.
stdlib.h: For the rand and exit functions.

Notes

The game reads in the sentences to be guessed from a text file called words.txt. Make sure that this file is in the same directory as the executable file.
The game uses ANSI escape codes to color the words. This feature may not work on all terminals.
