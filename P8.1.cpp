#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int a, b;

    try
    {
        cout << "Enter numerator: ";
        cin >> a;

        if(cin.fail())
            throw invalid_argument("Invalid input for numerator");

        cout << "Enter denominator: ";
        cin >> b;

        if(cin.fail())
            throw invalid_argument("Invalid input for denominator");

        if(b == 0)
            throw runtime_error("Division by zero not allowed");

        cout << "Result: " << (a / b) << endl;
    }
    catch(exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}