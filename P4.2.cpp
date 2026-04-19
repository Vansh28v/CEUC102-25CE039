#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int xVal = 0, int yVal = 0) {
        x = xVal;
        y = yVal;
    }

    Point& move(int dx, int dy) {
        x += dx;
        y += dy;
        return *this; 
    }

    // Display function
    void display() {
        cout << "Point (" << x << ", " << y << ")" << endl;
    }

    // Distance from origin
    double distanceFromOrigin() {
        return sqrt(x * x + y * y);
    }

    // Setter (used by pointer function)
    void set(int xVal, int yVal) {
        x = xVal;
        y = yVal;
    }
};


void updatePoint(Point* p, int dx, int dy) {
    p->move(dx, dy); 
}

void resetPoint(Point* p) {
    p->set(0, 0);
}

int main() {
    Point p(1, 2);

    cout << "Initial: ";
    p.display();

    p.move(2, 3).move(-1, 4).move(5, -2);

    cout << "After chained moves: ";
    p.display();

    updatePoint(&p, 3, 3);

    cout << "After pointer update: ";
    p.display();

    cout << "Distance from origin: " << p.distanceFromOrigin() << endl;

    resetPoint(&p);

    cout << "After reset: ";
    p.display();

    return 0;
}