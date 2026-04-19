#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string input;
    cout << "Enter a paragraph:\n";
    getline(cin, input);

    string words[100];  // array to store words
    int count[100] = {0};
    int wordCount = 0;

    string temp = "";

    // Extract words manually
    for (int i = 0; i <= input.length(); i++) {
        char ch = input[i];

        // Check if character is alphabet
        if (isalpha(ch)) {
            temp += tolower(ch);
        } else {
            if (temp != "") {
                words[wordCount++] = temp;
                temp = "";
            }
        }
    }

    // Display extracted words
    cout << "\nExtracted Words:\n";
    for (int i = 0; i < wordCount; i++) {
        cout << words[i] << " ";
    }

    // Count frequencies
    for (int i = 0; i < wordCount; i++) {
        if (count[i] == -1)
            continue;

        count[i] = 1;

        for (int j = i + 1; j < wordCount; j++) {
            if (words[i] == words[j]) {
                count[i]++;
                count[j] = -1; // mark as counted
            }
        }
    }

    // Display frequencies
    cout << "\n\nWord Frequencies:\n";
    for (int i = 0; i < wordCount; i++) {
        if (count[i] != -1) {
            cout << words[i] << " : " << count[i] << endl;
        }
    }

    return 0;
}