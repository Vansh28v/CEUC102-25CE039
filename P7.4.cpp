#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
    virtual float area() = 0; 

    virtual void display()
    {
        cout << "Shape Area: " << area() << endl;
    }

    virtual ~Shape() {} 
};

class Rectangle : public Shape
{
    float length, width;

public:
    Rectangle(float l, float w)
    {
        length = l;
        width = w;
    }

    float area()
    {
        return length * width;
    }

    void display()
    {
        cout << "Rectangle Area: " << area() << endl;
    }
};

class Circle : public Shape
{
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }

    float area()
    {
        return 3.14 * radius * radius;
    }

    void display()
    {
        cout << "Circle Area: " << area() << endl;
    }
};

int main()
{
 
    vector<Shape*> shapes;

    shapes.push_back(new Rectangle(5, 4));
    shapes.push_back(new Circle(3));

    cout << "--- Dynamic Storage ---\n";
    for(int i = 0; i < shapes.size(); i++)
    {
        shapes[i]->display();
    }

    Shape* staticShapes[2];
    staticShapes[0] = new Rectangle(2, 6);
    staticShapes[1] = new Circle(5);

    cout << "\n--- Static Storage ---\n";
    for(int i = 0; i < 2; i++)
    {
        staticShapes[i]->display();
    }

    for(int i = 0; i < shapes.size(); i++)
        delete shapes[i];

    for(int i = 0; i < 2; i++)
        delete staticShapes[i];

    return 0;
}