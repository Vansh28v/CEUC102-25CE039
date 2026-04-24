#include <iostream>
#include <iomanip>
using namespace std;


ostream& currency(ostream& output)
{
    output << "₹ ";
    return output;
}

int main()
{
    string name[5] = {"Aman", "Riya", "Kunal", "Neha", "Vansh"};
    int marks[5] = {85, 92, 76, 88, 95};
    float fees[5] = {25000.5, 26000.75, 24000.0, 25500.25, 27000.9};
    float percentage[5];

   
    for(int i = 0; i < 5; i++)
    {
        percentage[i] = marks[i];
    }

  
    cout << setfill('=') << setw(70) << "=" << endl;
    cout << setfill(' ');
    cout << left << setw(15) << "Name"
         << right << setw(10) << "Marks"
         << setw(15) << "Percentage"
         << setw(15) << "Fees" << endl;

    cout << setfill('=') << setw(70) << "=" << endl;
    cout << setfill(' ');

 
    for(int i = 0; i < 5; i++)
    {
        cout << left << setw(15) << name[i]
             << right << setw(10) << marks[i]
             << setw(13) << fixed << setprecision(2) << percentage[i] << "%"
             << setw(10);

        cout << currency << fixed << setprecision(2) << fees[i] << endl;
    }

    cout << setfill('=') << setw(70) << "=" << endl;

    return 0;
}