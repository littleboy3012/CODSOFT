//include all necessary header files
#include <iostream>
#include <stdlib.h>
using namespace std;

// create a function which will return an random number between 1 to 100
int Random()
{
    return rand() % 100;
}

//create a game function which wil take input from user and give feedback about number to user (High or Low)
void game()
{
    int random = Random();
    int no, cnt = 0;
Again:                  
    cout << "Enter your number : ";
    cin >> no;
    cnt++;

    if (no > random)
    {
        cout << "Your number is too High" << endl;
        goto Again;
    }
    else if (no < random)
    {
        cout << "Your number is too Low" << endl;
        goto Again;
    }
    else
    {
        cout << "Congo! You Guessed it right in " << cnt << " guesses" << endl
             << endl;
    }
}

int main()
{
    cout << "Guess the number between 1 to 100" << endl;

    int n = 1;

    //This while loop will run forever until user wants to quit the game
    while (n != 2)
    {
        cout << "Enter 1 to play" << endl;
        cout << "Enter 2 to quit" << endl;
        cout << "Enter your choice : ";
        cin >> n;

        //initialising switch case
        switch (n)
        {
        case 1:
            game();
            break;
        case 2:
            cout << "Thanks for playing" << endl;
            break;
        default:
            cout << "Wrong choice. Enter again." << endl;
        }
    }
    return 0;
}