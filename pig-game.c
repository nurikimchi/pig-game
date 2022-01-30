/* file: pig_game.c
 * A program that makes you play against the computer in a game of Pig.
 * author: Nuri Kim */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int dice, player_choice, player_round, player_total, comp_choice, comp_continue, comp_round, comp_total, comp_cycle;

void player () {
    srand(time(0));
    printf("Player's turn: \n");
        while (1) {
        printf(" [1] Roll \n [2] Hold \n");
        scanf("%d", &player_choice);

        if (player_choice == 1) {
            dice = 1 + rand() % 6;
            
            if (dice == 1) {
                printf("Uh-oh, you rolled a 1. All current round points removed. \n");
                player_round = 0;
                printf("Player total: %d \n", player_total);
                return;
            }

            printf("You rolled a %d \n", dice);
            player_round += dice;
            printf("Player round points: %d\n", player_round);
            continue;
        }

        if (player_choice == 2) {
            printf("You held.\n");
            player_total += player_round;
            printf("Player total: %d. \n", player_total);

            if (player_total >= 100) {
                printf("Player wins! \n");
                exit(0);
            }
            
            player_round = 0;
            return;
        }

        else {
            printf("Invalid input, please enter a number that is 1 or 2.\n");
            continue;
        }
    }   
} 

void computer () {
    srand(time(0));
    while (1) {
        comp_choice = 1 + rand () % 2;
        dice = 1 + rand () % 6;
        comp_cycle ++;

        if (comp_choice == 1) {
            dice = 1 + rand() % 6;

            if (dice == 1) {
                printf("Computer rolled a 1 so it's original total remains.\n");
                comp_round = 0;
                printf("Computer's total is %d: \n", comp_total);
                return;
            }

            comp_round += dice;
            printf("Computer rolled a %d \n", dice);
            
            if (comp_total >= 100) {
                printf("Computer wins!\n");
                exit(0);
            }

            while (1) {
                comp_continue = 1 + rand() % 2;
                break;
            }

            if (comp_continue == 1) {
                continue;
            }

            if (comp_continue == 2 && comp_cycle > 1) {
                comp_total += comp_round;
                printf("The computer held. \n");
                printf("Computer total: %d \n", comp_total);
                comp_round = 0;
                return;
            }
        }
    }
}

int main () {
    while (1) {
        player();
        computer();
    } 
}