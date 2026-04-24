#include <iostream>
using namespace std;

class InsufficientFundsException
{
    float amount;

public:
    InsufficientFundsException(float a)
    {
        amount = a;
    }

    float getAmount()
    {
        return amount;
    }
};

class BankAccount
{
    float balance;

public:
    BankAccount(float b)
    {
        balance = b;
    }

    void deposit(float amt)
    {
        if(amt <= 0)
            throw "Invalid deposit amount";
        balance += amt;
    }

    void withdraw(float amt)
    {
        if(amt > balance)
            throw InsufficientFundsException(amt);
        balance -= amt;
    }

    float getBalance()
    {
        return balance;
    }
};

string logs[100];
int logIndex = 0;

void addLog(string msg)
{
    logs[logIndex++] = msg;
}

void performWithdraw(BankAccount &acc, float amt)
{
    addLog("Entered performWithdraw");
    acc.withdraw(amt);
    addLog("Exit performWithdraw");
}

void processTransaction(BankAccount &acc, float amt)
{
    addLog("Entered processTransaction");
    performWithdraw(acc, amt);
    addLog("Exit processTransaction");
}

int main()
{
    BankAccount acc(5000);

    try
    {
        addLog("Start main");

        acc.deposit(1000);
        addLog("Deposit successful");

        processTransaction(acc, 2000);
        addLog("Withdrawal successful");

        processTransaction(acc, 6000);
        addLog("This will not execute");
    }
    catch(InsufficientFundsException e)
    {
        addLog("Exception: Insufficient funds for withdrawal");
    }
    catch(const char* msg)
    {
        addLog(msg);
    }

    cout << "Final Balance: " << acc.getBalance() << endl;

    cout << "\n--- Logs ---\n";
    for(int i = 0; i < logIndex; i++)
    {
        cout << logs[i] << endl;
    }

    return 0;
}