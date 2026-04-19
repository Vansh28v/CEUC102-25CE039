#include <iostream>
using namespace std;

// Recursive function to find super digit
int superDigit(long long num) {
    // Base case
    if (num < 10)
        return num;

    long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return superDigit(sum);
}

// Function to compute initial sum from string
long long initialSum(string n, int k) {
    long long sum = 0;

    for (char c : n) {
        sum += (c - '0');
    }

    return sum * k;
}

int main() {
    string n;
    int k;

    cout << "Enter number (as string): ";
    cin >> n;

    cout << "Enter k: ";
    cin >> k;

    long long result = initialSum(n, k);

    int ans = superDigit(result);

    cout << "Super Digit: " << ans << endl;

    return 0;
}