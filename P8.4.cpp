#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ifstream file;
    string path;

    while(true)
    {
        cout << "Enter file path: ";
        cin >> path;

        file.open(path);

        if(file.is_open())
            break;

        cout << "File not found. Try again.\n";
        file.clear();
    }

    string line;
    int lineNo = 0;
    float sum = 0;
    int count = 0;

    string errorLog[100];
    int errIndex = 0;

    while(getline(file, line))
    {
        lineNo++;
        stringstream ss(line);
        float num;
        bool valid = true;

        while(ss >> num)
        {
            sum += num;
            count++;
        }

        if(ss.fail() && !ss.eof())
        {
            valid = false;
        }

        if(!valid)
        {
            errorLog[errIndex++] = "Line " + to_string(lineNo) + ": " + line;
        }
    }

    file.close();

    cout << "\nSum: " << sum << endl;
    cout << "Count: " << count << endl;

    if(count > 0)
        cout << "Average: " << sum / count << endl;

    cout << "\n--- Corrupted Lines ---\n";
    for(int i = 0; i < errIndex; i++)
    {
        cout << errorLog[i] << endl;
    }

    return 0;
}