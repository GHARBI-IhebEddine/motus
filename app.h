#ifndef APP_H
#define APP_H

#include "words.h"
#include "menu.h"

// A struct to represent the game state
typedef struct {
Sentence sentences[100];
int numSentences;
int currentSentenceIndex;
Sentence currentSentence;
char guessedSentence[MAX_SENTENCE_LENGTH];
int gameOver;
int currentPlayer;
int numGuesses;
} Game;

// A function to initialize a new game
void initGame(Game* game);

// A function to run a round of the game
void playRound(Game* game);

#endif