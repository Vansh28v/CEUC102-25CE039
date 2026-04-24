#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Base Class
class Shape
{
protected:
    float radius;

public:
    void setRadius(float r)
    {
        if(r >= 0)
            radius = r;
        else
            radius = 0;
    }

    float getRadius()
    {
        return radius;
    }
};

// Derived Class
class Circle : public Shape
{
public:
    float area()
    {
        return 3.14 * radius * radius;
    }

    float circumference()
    {
        return 2 * 3.14 * radius;
    }

    string category()
    {
        float a = area();
        if(a < 50)
            return "Small";
        else if(a < 200)
            return "Medium";
        else
            return "Large";
    }
};

int main()
{
    int n;

    cout << "Enter number of circles: ";
    cin >> n;

    // -------- Dynamic Approach --------
    vector<Circle> dynCircles(n);

    cout << "\nEnter radius for dynamic circles:\n";
    for(int i = 0; i < n; i++)
    {
        float r;
        cout << "Circle " << i+1 << ": ";
        cin >> r;
        dynCircles[i].setRadius(r);
    }

    cout << "\nDynamic Circle Data:\n";
    cout << setw(10) << "Radius"
         << setw(15) << "Area"
         << setw(20) << "Circumference"
         << setw(15) << "Type" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << setw(10) << dynCircles[i].getRadius()
             << setw(15) << dynCircles[i].area()
             << setw(20) << dynCircles[i].circumference()
             << setw(15) << dynCircles[i].category()
             << endl;
    }

    // -------- Static Approach --------
    int m = 3;
    Circle staticCircles[3];

    cout << "\nEnter radius for 3 static circles:\n";
    for(int i = 0; i < m; i++)
    {
        float r;
        cout << "Circle " << i+1 << ": ";
        cin >> r;
        staticCircles[i].setRadius(r);
    }

    cout << "\nStatic Circle Data:\n";
    cout << setw(10) << "Radius"
         << setw(15) << "Area"
         << setw(20) << "Circumference"
         << setw(15) << "Type" << endl;

    for(int i = 0; i < m; i++)
    {
        cout << setw(10) << staticCircles[i].getRadius()
             << setw(15) << staticCircles[i].area()
             << setw(20) << staticCircles[i].circumference()
             << setw(15) << staticCircles[i].category()
             << endl;
    }

    return 0;
}