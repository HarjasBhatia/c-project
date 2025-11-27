#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matchstick_game.h"

int main() {
    int matchsticks = TOTAL_MATCHSTICKS;
    int playerTurn = 1;
    int move;
    int playerWins = 0, computerWins = 0;
    char playAgain;
    
    srand(time(NULL));
    
    printf("=== ENHANCED MATCHSTICK GAME ===\n");
    printf("Rules:\n");
    printf("- There are %d matchsticks\n", TOTAL_MATCHSTICKS);
    printf("- Each turn, pick %d to %d matchsticks\n", MIN_PICK, MAX_PICK);
    printf("- Player who takes the last matchstick LOSES!\n");
    printf("- Winning Strategy: Try to leave multiples of %d after your turn\n\n", MAX_PICK + 1);
    
    do {
        matchsticks = TOTAL_MATCHSTICKS;
        playerTurn = (rand() % 2);
        
        if (playerTurn) {
            printf("\n>>> You start first! <<<\n");
        } else {
            printf("\n>>> Computer starts first! <<<\n");
        }
        
        while (matchsticks > 0) {
            printf("\nRemaining matchsticks: %d\n", matchsticks);
            displayMatchsticks(matchsticks);
            
            if (playerTurn) {
                move = getUserMove(matchsticks);
                printf("You picked %d matchstick(s)\n", move);
            } else {
                move = getComputerMove(matchsticks);
                printf("Computer picked %d matchstick(s)\n", move);
            }
            
            matchsticks -= move;
            
            if (matchsticks == 0) {
                displayWinner(playerTurn);
                if (playerTurn) {
                    computerWins++;
                } else {
                    playerWins++;
                }
                break;
            }
            
            playerTurn = !playerTurn;
        }
        
        displayGameStats(playerWins, computerWins);
        
        printf("\nPlay again? (y/n): ");
        scanf(" %c", &playAgain);
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    printf("\nThanks for playing!\n");
    return 0;
}