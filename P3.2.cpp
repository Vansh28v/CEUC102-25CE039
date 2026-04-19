#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int recursiveSum(vector<int> &arr, int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}

int iterativeSum(vector<int> &arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    clock_t start, end;

    
    start = clock();
    int iterSum = iterativeSum(arr, n);
    end = clock();
    double iterTime = double(end - start) / CLOCKS_PER_SEC;

    
    start = clock();
    int recSum = recursiveSum(arr, n);
    end = clock();
    double recTime = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nIterative Sum = " << iterSum;
    cout << "\nRecursive Sum = " << recSum;

    cout << "\n\nExecution Time:";
    cout << "\nIterative Time = " << iterTime << " seconds";
    cout << "\nRecursive Time = " << recTime << " seconds";

    return 0;
}