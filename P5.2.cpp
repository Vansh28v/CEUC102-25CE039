#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("input.txt");

    if (!file) {
        cout << "Error: File could not be opened.\n";
        return 1;
    }

    string line;
    int lines = 0, words = 0, characters = 0;

    while (getline(file, line)) {
        lines++;

        bool inWord = false;

        for (int i = 0; i < line.length(); i++) {
            characters++; 

            if (line[i] != ' ' && line[i] != '\t') {
                if (!inWord) {
                    words++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }
        }

        characters++; 
    }

    file.close();

    cout << "\nFile Analysis:\n";
    cout << "Lines: " << lines << endl;
    cout << "Words: " << words << endl;
    cout << "Characters (including spaces): " << characters << endl;

    return 0;
}