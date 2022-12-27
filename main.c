#include <stdio.h>
#include "app.h"

int main() {
// Create a game struct
Game game;

// Display the main menu and get the user's choice
int choice = displayMenu();
// Loop until the user chooses to quit
while (choice != 3) {
if (choice == 1) {
// If the user chooses to start a new game, initialize the game
initGame(&game);

  // Loop until the game is over
  while (!game.gameOver) {
    // Play a round of the game
    playRound(&game);
  }
} else if (choice == 2) {
  // If the user chooses to continue a saved game, load the game state
  // (implementation not shown)
}

// Display the main menu and get the user's choice
choice = displayMenu();
}

return 0;
}