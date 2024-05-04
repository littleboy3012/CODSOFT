//include all necessary files
#include <iostream>
#include <iomanip>
using namespace std;

//crate class calcultor
class calculator
{
    float a, b;  //a and b will store operand
    int choice;  // This will store operator choice

public:

    //getData function will input operand from user
    void getData()
    {
        cout << "Enter first operand : ";
        cin >> a;
        cout << "Enter second operand : ";
        cin >> b;
    }

    //getChoice function will input operator choice from user
    void getChoice()
    {
        cout << "Enter 1-->Add" << endl;
        cout << "Enter 2-->Subtraction" << endl;
        cout << "Enter 3-->Multiply" << endl;
        cout << "Enter 4-->Divide" << endl;
        cout << "Enter type of operation you want to perform : ";
        cin >> choice;
    }

    //Function to perform operation and display result
    void opSelector()
    {
        switch (choice)
        {
        case 1:
            cout << a << " + " << b << " = " << add();
            break;
        case 2:
            cout << a << " - " << b << " = " << sub();
            break;
        case 3:
            cout << a << " * " << b << " = " << multiply();
            break;
        case 4:
            cout << a << " / " << b << " = " << divide();
            break;
        default:
            cout << "You have entered wrong choice" << endl;
        }
    }

    //return sum of a and b
    float add()
    {
        return a + b;
    }

    //return subtraction of a and b
    float sub()
    {
        return a - b;
    }

    //return multiplication of a and b
    float multiply()
    {
        return a * b;
    }

    //return division of a and b
    float divide()
    {
        return a / b;
    }
};

int main()
{
    cout << setw(30) << setfill('-') << "-" << endl;
    cout<<"          CALCULATOR"<<endl;
    cout << setw(30) << setfill('-') << "-" << endl;
    calculator c1;    //create object c1 of class calculator
    c1.getData();
    c1.getChoice();
    c1.opSelector();

    return 0;
}