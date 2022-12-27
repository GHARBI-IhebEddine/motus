#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "app.h"

void initGame(Game* game) {
// Open the text file for reading
FILE* file = fopen("words.txt", "r");
if (file == NULL) {
printf("Error: unable to open file.\n");
exit(1);
}

// Read in the sentences from the file
game->numSentences = 0;
while (!feof(file)) {
game->sentences[game->numSentences] = readSentence(file);
game->numSentences++;
}

// Close the file
fclose(file);

// Seed the random number generator
srand(time(0));

// Select a random sentence to be guessed
game->currentSentenceIndex = rand() % game->numSentences;
game->currentSentence = game->sentences[game->currentSentenceIndex];

// Initialize the guessed sentence to be empty
strcpy(game->guessedSentence, "");

// Set the game to be not over
game->gameOver = 0;

// Set the current player to be player 1
game->currentPlayer = 1;

// Set the number of guesses to be 0
game->numGuesses = 0;
}

void playRound(Game* game) {
// Print the current state of the guessed sentence
printf("Current guessed sentence: %s\n", game->guessedSentence);

// Get the next guess from the current player
char guess[MAX_WORD_LENGTH];
printf("Player %d, enter your guess: ", game->currentPlayer);
scanf("%s", guess);

// Check if the guess is correct
int wordIndex = checkWord(game->currentSentence, guess);
if (wordIndex != -1) {
// If the guess is correct, add it to the guessed sentence
strcat(game->guessedSentence, guess);
strcat(game->guessedSentence, " ");

// Check if the guessed sentence is complete
// Initialize a counter variable to track the number of words in the guessed sentence
int numGuessedWords = 0;

// Loop through the words in the guessed sentence
for (int i = 0; i < strlen(game->guessedSentence); i++) {
// If the current character is a space, increment the counter
if (game->guessedSentence[i] == ' ') {
numGuessedWords++;
}
}

// Check if the number of words in the guessed sentence is equal to the number of words in the current sentence
if (numGuessedWords == game->currentSentence.numWords) {
// If the guessed sentence is complete, the game is over
printf("Game over! Player %d wins.\n", game->currentPlayer);
game->gameOver = 1;
}
} else {
// If the guess is incorrect, increment the number of guesses
game->numGuesses++;

// Check if the game is over
if (game->numGuesses == 3) {
  // If the number of guesses is 3, the game is over and the other player wins
  printf("Game over! Player %d wins.\n", (game->currentPlayer % 2) + 1);
  game->gameOver = 1;
}
}

// Switch players if the game is not over
if (!game->gameOver) {
game->currentPlayer = (game->currentPlayer % 2) + 1;
}
}