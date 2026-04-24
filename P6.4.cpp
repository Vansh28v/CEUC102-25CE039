#include <iostream>
#include <vector>
using namespace std;

class Account
{
protected:
    int accNo;
    float balance;
    vector<float> transactions; 
public:
    Account(int a, float b)
    {
        accNo = a;
        balance = b;
    }

    virtual ~Account() {}

    void deposit(float amt)
    {
        balance += amt;
        transactions.push_back(amt);
    }

    virtual void withdraw(float amt) = 0; /

    void undoLast()
    {
        if(transactions.size() == 0)
        {
            cout << "No transaction to undo\n";
            return;
        }

        float last = transactions.back();
        balance -= last;
        transactions.pop_back();
        cout << "Last transaction undone\n";
    }

    void showTransactions()
    {
        cout << "Transactions: ";
        for(float t : transactions)
            cout << t << " ";
        cout << endl;
    }

    virtual void display()
    {
        cout << "Account No: " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }
};

class Savings : public Account
{
    float interestRate;

public:
    Savings(int a, float b, float r) : Account(a, b)
    {
        interestRate = r;
    }

    void withdraw(float amt)
    {
        if(amt <= balance)
        {
            balance -= amt;
            transactions.push_back(-amt);
        }
        else
            cout << "Insufficient balance\n";
    }

    void addInterest()
    {
        float interest = balance * interestRate / 100;
        balance += interest;
    }

    void display()
    {
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class Current : public Account
{
    float overdraftLimit;

public:
    Current(int a, float b, float limit) : Account(a, b)
    {
        overdraftLimit = limit;
    }

    void withdraw(float amt)
    {
        if(amt <= balance + overdraftLimit)
        {
            balance -= amt;
            transactions.push_back(-amt);
        }
        else
            cout << "Overdraft limit exceeded\n";
    }

    void display()
    {
        Account::display();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main()
{
    Savings s1(101, 5000, 5);
    Current c1(201, 3000, 2000);

    cout << "\n--- Savings Account ---\n";
    s1.deposit(1000);
    s1.withdraw(2000);
    s1.addInterest();
    s1.display();
    s1.showTransactions();
    s1.undoLast();
    s1.display();

    cout << "\n--- Current Account ---\n";
    c1.deposit(1500);
    c1.withdraw(4000);
    c1.display();
    c1.showTransactions();
    c1.undoLast();
    c1.display();

    return 0;
}