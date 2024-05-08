// include all necessary header files
#include <iostream>
using namespace std;

int player_wins[2] = {0, 0}; // keeps count of wins of both the players

// This function will display the current status of the board
void displayBoard(char board[3][3])
{
    cout << "-------------" << endl;
    for (int i = 0; i <= 2; i++)
    {
        cout << "|";
        for (int j = 0; j <= 2; j++)
        {
            cout << " " << board[i][j] << " |";
        }
        cout << "\n-------------" << endl;
    }
}

// This function will check if player have won or not
bool checkWin(char board[3][3], char player)
{
    // first check col and rows
    for (int i = 0; i <= 2; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // check for diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// This will check if game is draw, then it will display game draws
void checkDraw(char board[3][3])
{
    if (!(checkWin(board, 'X') || checkWin(board, 'O')))
    {
        cout << "Game Draws" << endl;
    }
}

// This will check if board have any blank space than it will return true
bool checkEmpty(char board[3][3])
{
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (board[i][j] == ' ')
                return true;
        }
    }
    return false;
}

// This function will take inputs from user, display board and check for win
void game(char (*board)[3], char player, int k)
{
    int row, col;
Again:
    cout << "Player " << k << " enter row(0-2) and colunm(0-2) : ";
    cin >> row >> col;
    if (board[row][col] == ' ')
    {
        board[row][col] = player;
    }
    else
    {
        cout << "Inavalid Position" << endl;
        goto Again;
    }

    displayBoard(board);

    if (checkWin(board, player) == true)
    {
        cout << "Player " << k << " wins" << endl;
        player_wins[k - 1]++;
    }
}

// This function will clear the board
void cleanBoard(char (*board)[3])
{
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            board[i][j] = ' ';
        }
    }
}

int main()
{
    char Board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; // initialise 3X3 2D array with blank space
    int choice;
    char player1, player2;

    cout << "\n--------------------------\n";
    cout << "Welcome to the Tic-Tac-Toe Game" << endl;
    cout << "Player 1 select X or O : ";
    cin >> player1;
    player2 = (player1 == 'X') ? ('O') : ('X');
    cout << "Player 1 : " << player1 << endl;
    cout << "Player 2 : " << player2 << endl;

Again:
    while (checkEmpty(Board) && !(checkWin(Board, player1) || checkWin(Board, player2))) // This while loop will continue until board is empty and none of the player have won yet
    {
        game(&Board[0], player1, 1);

        if (!checkEmpty(Board) || checkWin(Board, player1) || checkWin(Board, player2)) // if bboard is full or any player have won then it will go to 'Again'
            goto Again;

        game(&Board[0], player2, 2);
    }

    checkDraw(Board);

    cout << "Enter 1--->Play again" << endl;
    cout << "Enter 2--->Quit" << endl;
    cin >> choice;
    if (choice == 1)
    {
        cleanBoard(&Board[0]);
        char temp = player1; // Interchanging 'X' and 'O' of both player
        player1 = player2;
        player2 = temp;
        cout << "Player 1 : " << player1 << endl;
        cout << "Player 2 : " << player2 << endl;
        goto Again;
    }

    // Finally display wins of both the player
    cout << "Player 1 won " << player_wins[0] << " times" << endl;
    cout << "Player 2 won " << player_wins[1] << " times" << endl;

    return 0;
}