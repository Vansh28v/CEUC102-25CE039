#include <iostream>
#include <vector>
using namespace std;

class Calculator
{
    vector<float> results;

public:

    int add(int a, int b)
    {
        int res = a + b;
        results.push_back(res);
        return res;
    }

    float add(float a, float b)
    {
        float res = a + b;
        results.push_back(res);
        return res;
    }

    float add(int a, float b)
    {
        float res = a + b;
        results.push_back(res);
        return res;
    }

    float subtract(float a, float b)
    {
        float res = a - b;
        results.push_back(res);
        return res;
    }

    float multiply(float a, float b)
    {
        float res = a * b;
        results.push_back(res);
        return res;
    }

    float divide(float a, float b)
    {
        if(b == 0)
        {
            cout << "Division by zero not allowed\n";
            return 0;
        }
        float res = a / b;
        results.push_back(res);
        return res;
    }

    float addArray(float arr[], int n)
    {
        float sum = 0;
        for(int i = 0; i < n; i++)
            sum += arr[i];

        results.push_back(sum);
        return sum;
    }

    void displayResults()
    {
        cout << "\n--- Results ---\n";
        for(int i = 0; i < results.size(); i++)
        {
            cout << "Result " << i+1 << ": " << results[i] << endl;
        }
    }
};

int main()
{
    Calculator calc;

    cout << "Add int: " << calc.add(10, 20) << endl;
    cout << "Add float: " << calc.add(5.5f, 2.3f) << endl;
    cout << "Add mixed: " << calc.add(10, 3.5f) << endl;

    cout << "Subtract: " << calc.subtract(10, 4) << endl;
    cout << "Multiply: " << calc.multiply(3, 5) << endl;
    cout << "Divide: " << calc.divide(10, 2) << endl;

    float arr[3] = {1.5, 2.5, 3.0};
    cout << "Sum of array: " << calc.addArray(arr, 3) << endl;

    calc.displayResults();

    return 0;
}