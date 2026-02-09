#include <iostream>
using namespace std;

class Account {
private:
    string name;
    int id;
    double balance;

public:


    void setData(string n, int i, double b) {
        name = n;
        id = i;

        if (b >= 0)
            balance = b;
        else
            balance = 0;
    }

    void deposit(double amt) {
        if (amt > 0)
            balance += amt;
        else
            cout << "Invalid deposit!\n";
    }

    void withdraw(double amt) {
        if (amt > balance)
            cout << "Not enough balance!\n";
        else if (amt > 0)
            balance -= amt;
        else
            cout << "Invalid amount!\n";
    }

    void display() {
        cout << "\nName: " << name;
        cout << "\nID: " << id;
        cout << "\nBalance: " << balance << endl;
    }
};

int main() {

    int n;
    cout << "Enter number of accounts: ";
    cin >> n;

    Account a[100];

    for (int i = 0; i < n; i++) {

        string name;
        int id;
        double bal;

        cout << "\nEnter details for Account " << i + 1 << endl;

        cout << "Name: ";
        cin >> name;

        cout << "ID: ";
        cin >> id;

        cout << "Initial Balance: ";
        cin >> bal;

        a[i].setData(name, id, bal);
    }


    for (int i = 0; i < n; i++) {

        double d, w;

        cout << "\nFor Account " << i + 1 << endl;

        cout << "Enter deposit amount: ";
        cin >> d;
        a[i].deposit(d);

        cout << "Enter withdraw amount: ";
        cin >> w;
        a[i].withdraw(w);
    }


    cout << "\n--- Account Summary ---\n";

    for (int i = 0; i < n; i++) {
        a[i].display();
    }

    return 0;
}
