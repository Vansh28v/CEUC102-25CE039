#include <iostream>
#include <cmath>
using namespace std;

class NegativeNumberException
{
    float value;

public:
    NegativeNumberException(float v)
    {
        value = v;
    }

    void show()
    {
        cout << "Error: Negative number (" << value << ") not allowed for square root\n";
    }
};

int main()
{
    float num;

    try
    {
        cout << "Enter a number: ";
        cin >> num;

        if(num < 0)
            throw NegativeNumberException(num);

        cout << "Square root: " << sqrt(num) << endl;
    }
    catch(NegativeNumberException e)
    {
        e.show();
    }

    return 0;
}