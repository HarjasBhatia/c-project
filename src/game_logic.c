#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matchstick_game.h"

int isValidMove(int move, int remaining) {
    return (move >= MIN_PICK && move <= MAX_PICK && move <= remaining);
}

int getUserMove(int remaining) {
    int move;
    
    while (1) {
        printf("\nYour turn! Pick %d-%d matchsticks: ", MIN_PICK, MAX_PICK);
        
        if (scanf("%d", &move) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        
        if (isValidMove(move, remaining)) {
            break;
        } else {
            printf("Invalid move! You can pick %d to %d matchsticks ", MIN_PICK, MAX_PICK);
            printf("(and not more than %d remaining).\n", remaining);
        }
    }
    
    return move;
}

int getComputerMove(int remaining) {
    int move;

    /* misere version (last pick loses) strategy:
       To force the opponent to take the last matchstick, try to leave
       a pile size that is 1 (mod MAX_PICK+1) after this move.
    */
    int target = (remaining - 1) % (MAX_PICK + 1);
    if (target == 0) {
        if (remaining <= MAX_PICK) {
            move = remaining; /* take all when only few remain */
        } else {
            move = 1; /* small, simple choice */
        }
    } else {
        move = target; /* leave (modulus) 1 for opponent */
    }

    if (!isValidMove(move, remaining)) {
        move = (remaining > MAX_PICK) ? MAX_PICK : remaining;
    }

    return move;
}

void displayWinner(int player) {
    printf("\n");
    printf("=================================\n");
    if (player) {
        printf("   YOU LOSE! Computer wins!\n");
        printf("   You took the last matchstick!\n");
    } else {
        printf("   YOU WIN! Congratulations!\n");
        printf("   Computer took the last matchstick!\n");
    }
    printf("=================================\n");
}

void displayGameStats(int playerWins, int computerWins) {
    printf("\n=== GAME STATISTICS ===\n");
    printf("Your wins: %d\n", playerWins);
    printf("Computer wins: %d\n", computerWins);
    printf("Total games: %d\n", playerWins + computerWins);
    
    if (playerWins + computerWins > 0) {
        float winRate = (float)playerWins / (playerWins + computerWins) * 100;
        printf("Your win rate: %.1f%%\n", winRate);
    }
}