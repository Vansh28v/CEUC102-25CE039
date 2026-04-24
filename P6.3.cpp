#include <iostream>
#include <queue>
using namespace std;

class Fuel
{
protected:
    string fuelType;

public:
    Fuel(string f)
    {
        if(f == "petrol" || f == "diesel" || f == "electric")
            fuelType = f;
        else
            fuelType = "unknown";
    }

    void showFuel()
    {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Brand
{
protected:
    string brandName;

public:
    Brand(string b)
    {
        brandName = b;
    }

    void showBrand()
    {
        cout << "Brand: " << brandName << endl;
    }
};

class Car : public Fuel, public Brand
{
public:
    Car(string f, string b) : Fuel(f), Brand(b) {}

    void display()
    {
        showBrand();
        showFuel();
        cout << "----------------------" << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of cars: ";
    cin >> n;

    queue<Car> serviceQueue;

    for(int i = 0; i < n; i++)
    {
        string fuel, brand;
        cout << "\nCar " << i+1 << endl;
        cout << "Enter Brand: ";
        cin >> brand;
        cout << "Enter Fuel (petrol/diesel/electric): ";
        cin >> fuel;

        serviceQueue.push(Car(fuel, brand));
    }

    cout << "\n--- Service Queue Processing ---\n";
    while(!serviceQueue.empty())
    {
        Car c = serviceQueue.front();
        c.display();
        serviceQueue.pop();
    }

    Car staticCars[2] = {
        Car("petrol", "Toyota"),
        Car("electric", "Tesla")
    };

    cout << "\n--- Static Car Data ---\n";
    for(int i = 0; i < 2; i++)
    {
        staticCars[i].display();
    }

    return 0;
}