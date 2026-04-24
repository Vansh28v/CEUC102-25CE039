#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Complex
{
    float real, imag;

public:
    Complex(float r = 0, float i = 0)
    {
        real = r;
        imag = i;
    }

    Complex operator+(Complex c)
    {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(Complex c)
    {
        return Complex(real - c.real, imag - c.imag);
    }

    void operator+=(Complex c)
    {
        real += c.real;
        imag += c.imag;
    }

    void operator*=(Complex c)
    {
        float r = real * c.real - imag * c.imag;
        float i = real * c.imag + imag * c.real;
        real = r;
        imag = i;
    }

    float magnitude()
    {
        return sqrt(real * real + imag * imag);
    }

    float phase()
    {
        return atan2(imag, real);
    }

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c1(3, 4), c2(1, 2);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "Sum: ";
    sum.display();

    cout << "Difference: ";
    diff.display();

   
    c1 += c2;
    cout << "After += : ";
    c1.display();

    c1 *= c2;
    cout << "After *= : ";
    c1.display();

    cout << "Magnitude: " << c1.magnitude() << endl;
    cout << "Phase: " << c1.phase() << endl;

    vector<Complex> arr;
    arr.push_back(Complex(1, 1));
    arr.push_back(Complex(2, 2));
    arr.push_back(Complex(3, 3));

    Complex total;
    for(int i = 0; i < arr.size(); i++)
    {
        total += arr[i];
    }

    cout << "Batch Sum: ";
    total.display();

    return 0;
}