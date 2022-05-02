//  These are the libraries needed for making the TicTacToe game
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//  Created by Tasneem Hasanat on 5/1/22.

//  These are the global variables
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';


//  These are the prototype functions
void resetBoard(void);
void printBoard(void);
int checkFreeSpaces(void);
void playerMove(void);
void computerMove(void);
char checkWinner(void);
void printWinnner(char);


//  These are the main driver functions
int main()
{
    char winner = ' '; //Initialize as no winner as blank
    
    resetBoard();      //Initialize board reset for new game
    
    while (winner == ' ' && checkFreeSpaces() != 0)
    {
        printBoard();      //Initialize board to view in console
        
        playerMove();
        
        winner = checkWinner();
        
        if (winner != ' ' && checkFreeSpaces() == 0)
        {
            break;
        }
        computerMove();
        
        winner = checkWinner();
        
        if (winner != ' ' && checkFreeSpaces() == 0)
        {
            break;
        }
    }
   
    printBoard();
    printWinnner(winner);
   
    return 0;
}


void resetBoard() // We make 2 for loops printing blanks in the 2D array
{
    for (int i = 0; i<3; i++) // This enables us to reset the board
    {
        for (int j = 0; j<3; j++)
        {
            board[i][j] = ' ';
        }
    }
        
}
void printBoard() //Printing board on console for player
{
    //%c format specifers are placeholders
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkFreeSpaces()   //This function checks free spaces to determine if game is over or not
{
    int freeSpaces = 9;     // Initially in tictactoe there is 9 free spaces in the 2D array
    
    for (int i = 0; i<3; i++)   // Nested for-loop to check thru the 2D array for blankspaces
    {
        for (int j= 0; j<3; j++)    // For every occupied space by X or O we decrement freeSpace var by 1
        {
            if (board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces; // This var will reach zero, and return 0 thus ending the game when no moves remain
}
void playerMove()
{
    do {
        int x;  // local variables x and y to take user input
        int y;
        printf("Enter row number(1-3): ");
        scanf("%d", &x); // We take user input in terms of int and store in address(&) of var int x
        x--;
        printf("Enter column number(1-3): ");
        scanf("%d", &y);
        y--;
        if (board[x][y] != ' ')
        {
            printf("Invalid move\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
}
void computerMove()
{
    // computer makes random moves, so we create a seed based on current time
    srand(time(0));
    int x;
    int y;
    
    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3; // Generates 2 random numb between 0 -> 2 due to mod 3
            y = rand() % 3;
        } while (board[x][y] != ' ');
        
        board[x][y] = COMPUTER;
        
    }
    else
    {
        printWinnner(' ');
    }
}
char checkWinner()
{
    
    // Check Rows
    
    for (int i=0; i<3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    
    // Check Columns
    
    for (int i=0; i<3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    
    // Check Diagonals
    
        if (board[0][0] == board[2][2] && board[0][0] == board[2][2])
        {
            return board[0][0];
        }
        if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        {
            return board[0][2];
        }
    
    return ' ';         //  Return empty character so that there is no winner.
    
 }

void printWinnner(char winner)
{
    if (winner == PLAYER)
    {
        printf("YOU WIN!");
    }
    else if (winner == COMPUTER)
    {
        printf("YOU LOSE!");
    }
    else
    {
        printf("IT'S A TIE!");
    }
}
