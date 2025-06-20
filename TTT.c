#include <stdio.h>
#include <conio.h>
char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int checkwin();
void board();
void main() {
    int player = 1, i, choice;
    char mark;
    printf("\n\n\t***Tic-Tac-Toe***\n\n");
    printf("The following are the Rules to win this game : \n");
    printf("\n1. The player must occupy any 3 continueous positions which can be in the form of : \n");
    printf("\t1.1. Horizontal\n\t1.2. Vertical\n\t1.3. Diagonal\n");
    printf("\n2. If in case any user entered the occupied position as input, then it is an invalid move.\n");
    printf("But he will get another chance upto when he entered an unoccupied position as input.\n");
    printf("\n3. If one user selected a position, then he must wait to get his chance unitl the other user");
    printf("selected his position.\n");
    printf("\n4. There is no 'UNDO' option for both the users.\n");
    printf("\n\n\t***Best of Luck for both the players***\n\n");
    printf("\tplayer 1 can start the game now...!");
    do {
        board();
        player = (player % 2) ? 1 : 2;
        printf("Now, Player %d can choose and enter a number from above positions : ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'O' : 'X';
        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else {
            printf("\n'%d' is an Invalid move!\nPlease try again with another position.",choice);
            player--;
        }
        i = checkwin();
        player++;
    }while (i == - 1);
    board();
    printf("Match has completed.\nThe result is : \n\n");
    if (i == 1) {
        printf("Sorry for saying this.\n==>Player '%d' lost the match.\n\n",player);
        printf("Congratulations Player '%d'\n", --player);
        printf("==>Player %d Wins the match.\n", player);
    }
    else { //i == 0
        printf("==>Game draw");
        printf("Both players gave tough compition.");
    }
}
/* The following are the condition explaination for checkwin() :
1. '1' for game is over with win result
2. '-1' for game is in progress
3. 'O' for game is draw */
int checkwin() {
    if ( square[1] == square[2] && square[2] == square[3] || square[4] == square[5] && square[5] == square[6] || square[7] == square[8] && square[8] == square[9] || square[1] == square[4] && square[4] == square[7] || square[2] == square[5] && square[5] == square[8] || square[3] == square[6] && square[6] == square[9] || square[1] == square[5] && square[5] == square[9] || square[3] == square[5] && square[5] == square[7] )
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return - 1;
}
void board() {
    printf("\n\n\n\n\nPlayer 1 (O) - Player 2 (X)\n\n");
    printf("     |     | \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);
    printf("_____|_____|_____\n");
    printf("     |     | \n");
    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);
    printf("_____|_____|_____\n");
    printf("     |     | \n");
    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);
    printf("     |     | \n\n");
}