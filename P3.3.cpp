#include <iostream>
#include <vector>
using namespace std;

class Account {
private:
    int accountNumber;
    string name;
    double balance;
    int transactionCount;

public:
    static int totalAccounts;

    Account(int accNo, string n, double bal) {
        accountNumber = accNo;
        name = n;
        balance = bal;
        transactionCount = 0;
        totalAccounts++;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        transactionCount++;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
            return false;
        }
        balance -= amount;
        transactionCount++;
        return true;
    }

    void display() {
        cout << "\nAccount No: " << accountNumber;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance;
        cout << "\nTransactions: " << transactionCount << endl;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }
};

int Account::totalAccounts = 0;

int findAccount(vector<Account> &accounts, int accNo) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNo)
            return i;
    }
    return -1;
}

int main() {
    vector<Account> accounts;
    int choice;

    do {
        cout << "\n\n1. Add Account";
        cout << "\n2. Transfer Money";
        cout << "\n3. Display Accounts";
        cout << "\n4. Total Accounts";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int accNo;
            string name;
            double balance;

            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> balance;

            accounts.push_back(Account(accNo, name, balance));
        }

        else if (choice == 2) {
            int fromAcc, toAcc;
            double amount;

            cout << "Enter Sender Account: ";
            cin >> fromAcc;
            cout << "Enter Receiver Account: ";
            cin >> toAcc;
            cout << "Enter Amount: ";
            cin >> amount;

            int fromIndex = findAccount(accounts, fromAcc);
            int toIndex = findAccount(accounts, toAcc);

            if (fromIndex == -1 || toIndex == -1) {
                cout << "Invalid account number!\n";
            } else {
                if (accounts[fromIndex].withdraw(amount)) {
                    accounts[toIndex].deposit(amount);
                    cout << "Transfer successful!\n";
                }
            }
        }

        else if (choice == 3) {
            for (auto &acc : accounts) {
                acc.display();
            }
        }

        else if (choice == 4) {
            cout << "Total Accounts: " << Account::getTotalAccounts() << endl;
        }

    } while (choice != 5);

    return 0;
}
