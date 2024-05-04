#include <iostream>
#include <stdlib.h>
using namespace std;

class guessGame
{
public:
    int Random()
    {
        return rand() % 100;
    }

    void game()
    {
        int random = Random();
        int no,cnt=0;
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
            cout << "your number is too Low" << endl;
            goto Again;
        }
        else
        {
            cout << "Congo! You Guessed it right in "<<cnt<<" guesses"<<endl<< endl;
        }
    }
};

int main()
{
    guessGame c1;
    cout << "Guess the number between 1 to 100" << endl;

    int n;
    while (n != 2)
    {
        cout << "Enter 1 to play" << endl;
        cout << "Enter 2 to quit" << endl;
        cout << "Enter your choice : ";
        cin >> n;

        switch (n)
        {
        case 1:
            c1.game();
            break;
        case 2:
            cout<<"Thanks for playing"<<endl;
            break;
        default:
            cout<<"Wrong choice. Enter again."<<endl;
        }
    }
    return 0;
}