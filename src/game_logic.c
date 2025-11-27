#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matchstick_game.h"

void displayMatchsticks(int count) {
    if (count > 20) {
        printf("Matchsticks: ");
        for (int i = 0; i < 20; i++) {
            printf("|");
        }
        printf("... (%d total)\n", count);
    } else {
        printf("Matchsticks: ");
        for (int i = 0; i < count; i++) {
            printf("|");
        }
        printf(" (%d)\n", count);
    }
}

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
    int optimalMove;
    
    printf("\nComputer's turn...\n");
    
    optimalMove = remaining % (MAX_PICK + 1);
    
    if (optimalMove == 0) {
        if (rand() % 3 == 0 && remaining > MAX_PICK) {
            move = (rand() % MAX_PICK) + 1;
        } else {
            move = (rand() % MAX_PICK) + 1;
            if (move > remaining) move = remaining;
        }
    } else {
        move = optimalMove;
        
        if (rand() % 100 < 15 && remaining > move + MAX_PICK) {
            int alternateMove = (rand() % MAX_PICK) + 1;
            if (alternateMove != move && isValidMove(alternateMove, remaining)) {
                move = alternateMove;
            }
        }
    }
    
    if (!isValidMove(move, remaining)) {
        move = (remaining > MAX_PICK) ? MAX_PICK : remaining;
    }
    
    for (int i = 0; i < 100000000; i++);
    
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