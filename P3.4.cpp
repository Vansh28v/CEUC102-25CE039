#include <iostream>
using namespace std;

// Display array
template <typename T>
void display(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Find maximum element
template <typename T>
T findMax(T arr[], int n) {
    T max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Reverse array
template <typename T>
void reverseArray(T arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

// Find leader elements
template <typename T>
void findLeaders(T arr[], int n) {
    T maxRight = arr[n - 1];
    cout << "Leaders: " << maxRight << " ";

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxRight) {
            maxRight = arr[i];
            cout << maxRight << " ";
        }
    }
    cout << endl;
}

int main() {
    int n = 6;

    // Integer array
    int intArr[] = {16, 17, 4, 3, 5, 2};

    // Float array
    float floatArr[] = {1.2, 3.5, 2.8, 7.1, 0.5, 6.3};

    // Character array
    char charArr[] = {'a', 'z', 'b', 'y', 'c', 'x'};

    cout << "---- Integer Array ----\n";
    display(intArr, n);
    cout << "Max: " << findMax(intArr, n) << endl;
    reverseArray(intArr, n);
    cout << "Reversed: ";
    display(intArr, n);
    findLeaders(intArr, n);

    cout << "\n---- Float Array ----\n";
    display(floatArr, n);
    cout << "Max: " << findMax(floatArr, n) << endl;
    reverseArray(floatArr, n);
    cout << "Reversed: ";
    display(floatArr, n);
    findLeaders(floatArr, n);

    cout << "\n---- Character Array ----\n";
    display(charArr, n);
    cout << "Max (ASCII): " << findMax(charArr, n) << endl;
    reverseArray(charArr, n);
    cout << "Reversed: ";
    display(charArr, n);
    findLeaders(charArr, n);

    return 0;
}