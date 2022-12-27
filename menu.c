#include <stdio.h>
#include "menu.h"

int displayMenu() {
// Display the main menu options
printf("Word Game\n\n");
printf("1. Start a new game\n");
printf("2. Continue a saved game\n");
printf("3. Quit\n\n");
printf("Enter your choice: ");

// Get the user's choice
int choice;
scanf("%d", &choice);

return choice;
}