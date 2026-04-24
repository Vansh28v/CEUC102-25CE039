#include <iostream>
using namespace std;

class Base1
{
public:
    Base1()
    {
        cout << "Base1 Constructor\n";
    }

    ~Base1()
    {
        cout << "Base1 Destructor\n";
    }
};

class Derived1 : public Base1
{
    int *data;

public:
    Derived1()
    {
        data = new int[5];
        cout << "Derived1 Constructor\n";
    }

    ~Derived1()
    {
        delete[] data;
        cout << "Derived1 Destructor\n";
    }
};

class Base2
{
public:
    Base2()
    {
        cout << "\nBase2 Constructor\n";
    }

    virtual ~Base2()
    {
        cout << "Base2 Destructor\n";
    }
};

class Derived2 : public Base2
{
    int *data;

public:
    Derived2()
    {
        data = new int[5];
        cout << "Derived2 Constructor\n";
    }

    ~Derived2()
    {
        delete[] data;
        cout << "Derived2 Destructor\n";
    }
};

int main()
{
    cout << "---- Without Virtual Destructor ----\n";
    Base1 *b1 = new Derived1();
    delete b1;

    cout << "\n---- With Virtual Destructor ----\n";
    Base2 *b2 = new Derived2();
    delete b2;

    return 0;
}