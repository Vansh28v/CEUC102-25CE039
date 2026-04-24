#include <iostream>
#include <queue>
using namespace std;

class Fahrenheit; 
class Celsius
{
    float temp;

public:
    Celsius(float t = 0)
    {
        temp = t;
    }

    float getTemp()
    {
        return temp;
    }

    operator Fahrenheit();

    bool operator==(Celsius c)
    {
        return temp == c.temp;
    }

    bool operator>(Celsius c)
    {
        return temp > c.temp;
    }

    bool operator<(Celsius c)
    {
        return temp < c.temp;
    }

    void display()
    {
        cout << temp << " °C";
    }
};

class Fahrenheit
{
    float temp;

public:
    Fahrenheit(float t = 0)
    {
        temp = t;
    }

    float getTemp()
    {
        return temp;
    }

    operator Celsius()
    {
        return Celsius((temp - 32) * 5 / 9);
    }

    void display()
    {
        cout << temp << " °F";
    }
};

Celsius::operator Fahrenheit()
{
    return Fahrenheit((temp * 9 / 5) + 32);
}

int main()
{
    Celsius c1(25);
    Fahrenheit f1 = c1;

    cout << "Celsius to Fahrenheit: ";
    c1.display();
    cout << " = ";
    f1.display();
    cout << endl;

    Fahrenheit f2(77);
    Celsius c2 = f2;

    cout << "Fahrenheit to Celsius: ";
    f2.display();
    cout << " = ";
    c2.display();
    cout << endl;

    if(c1 == c2)
        cout << "Temperatures are equal\n";
    else
        cout << "Temperatures are not equal\n";

    queue<Celsius> q;
    q.push(Celsius(10));
    q.push(Celsius(20));
    q.push(Celsius(30));

    cout << "\n--- Queue Processing ---\n";
    while(!q.empty())
    {
        Fahrenheit f = q.front();
        q.front().display();
        cout << " -> ";
        f.display();
        cout << endl;
        q.pop();
    }

    Celsius arr[3] = {Celsius(0), Celsius(50), Celsius(100)};

    cout << "\n--- Static Storage ---\n";
    for(int i = 0; i < 3; i++)
    {
        Fahrenheit f = arr[i];
        arr[i].display();
        cout << " -> ";
        f.display();
        cout << endl;
    }

    return 0;
}