#include <iostream>
#include <string>

using namespace std;

class Wallet
{
private:
    int walletID;
    string userName;
    double balance;
    bool isFrozen;

public:

    void create(int id);
    bool load(double amt);
    void display();
    bool freeze();
    bool unfreeze();
    bool withdraw(double amt);

    int getID();
    bool frozen();
    double getBalance();
};



void Wallet::create(int id)
{
    walletID = id;

    cout << "Enter Name --> ";
    cin.ignore();
    getline(cin, userName);

    cout << "Enter Balance --> ";
    cin >> balance;

    isFrozen = false;

    cout << "Wallet Created Successfully!\n";
}


bool Wallet::load(double amt)
{
    if(isFrozen)
    {
        cout << "Wallet is Frozen! Cannot Load.\n";
        return false;
    }

    if(amt <= 0)
    {
        cout << "Invalid Amount!\n";
        return false;
    }

    balance += amt;
    cout << "Money Loaded Successfully!\n";

    return true;
}


void Wallet::display()
{
    cout << "\n----- Wallet Details -----\n";
    cout << "ID      : " << walletID << endl;
    cout << "Name    : " << userName << endl;
    cout << "Balance : " << balance << endl;
    cout << "Status  : " << (isFrozen ? "Frozen" : "Active") << endl;
}


bool Wallet::freeze()
{
    if(isFrozen)
    {
        cout << "Wallet Already Frozen!\n";
        return false;
    }

    isFrozen = true;
    cout << "Wallet Frozen Successfully!\n";
    return true;
}


bool Wallet::unfreeze()
{
    if(!isFrozen)
    {
        cout << "Wallet Already Active!\n";
        return false;
    }

    isFrozen = false;
    cout << "Wallet Unfrozen Successfully!\n";
    return true;
}


bool Wallet::withdraw(double amt)
{
    if(isFrozen)
    {
        cout << "Wallet is Frozen!\n";
        return false;
    }

    if(amt <= 0)
    {
        cout << "Invalid Amount!\n";
        return false;
    }

    if(balance < amt)
    {
        cout << "Insufficient Balance!\n";
        return false;
    }

    balance -= amt;
    return true;
}


int Wallet::getID()
{
    return walletID;
}

bool Wallet::frozen()
{
    return isFrozen;
}

double Wallet::getBalance()
{
    return balance;
}



int findWallet(Wallet W[], int last, int id)
{
    for(int i = 0; i < last; i++)
    {
        if(W[i].getID() == id)
            return i;
    }

    return -1;
}



int main()
{
    Wallet W[20];

    int last = 0;
    int ch;

    while(true)
    {
        cout << "\n====== WALLET MENU ======\n";
        cout << "1. Create Wallet\n";
        cout << "2. Load Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Freeze Wallet\n";
        cout << "5. Unfreeze Wallet\n";
        cout << "6. Transfer Money\n";
        cout << "7. Exit\n";

        cout << "Enter Choice --> ";
        cin >> ch;


        if(ch == 1)
        {
            if(last >= 20)
            {
                cout << "Maximum Wallet Limit Reached!\n";
                continue;
            }

            int id;
            cout << "Enter Wallet ID --> ";
            cin >> id;

            if(findWallet(W, last, id) != -1)
            {
                cout << "Wallet ID Already Exists!\n";
                continue;
            }

            W[last].create(id);
            last++;
        }


        

        else if(ch == 2)
        {
            int id;
            double amt;

            cout << "Enter Wallet ID --> ";
            cin >> id;

            int pos = findWallet(W, last, id);

            if(pos == -1)
            {
                cout << "Wallet Not Found!\n";
                continue;
            }

            cout << "Enter Amount --> ";
            cin >> amt;

            W[pos].load(amt);
        }


        

        else if(ch == 3)
        {
            int id;

            cout << "Enter Wallet ID --> ";
            cin >> id;

            int pos = findWallet(W, last, id);

            if(pos == -1)
            {
                cout << "Wallet Not Found!\n";
                continue;
            }

            W[pos].display();
        }



        else if(ch == 4)
        {
            int id;

            cout << "Enter Wallet ID --> ";
            cin >> id;

            int pos = findWallet(W, last, id);

            if(pos == -1)
            {
                cout << "Wallet Not Found!\n";
                continue;
            }

            W[pos].freeze();
        }



        else if(ch == 5)
        {
            int id;

            cout << "Enter Wallet ID --> ";
            cin >> id;

            int pos = findWallet(W, last, id);

            if(pos == -1)
            {
                cout << "Wallet Not Found!\n";
                continue;
            }

            W[pos].unfreeze();
        }


        else if(ch == 6)
        {
            int fromID, toID;
            double amt;

            cout << "Sender Wallet ID --> ";
            cin >> fromID;

            cout << "Receiver Wallet ID --> ";
            cin >> toID;

            int fromPos = findWallet(W, last, fromID);
            int toPos   = findWallet(W, last, toID);

            if(fromPos == -1 || toPos == -1)
            {
                cout << "One or Both Wallets Not Found!\n";
                continue;
            }

            if(fromID == toID)
            {
                cout << "Cannot Transfer to Same Wallet!\n";
                continue;
            }

            cout << "Enter Amount --> ";
            cin >> amt;

            if(W[fromPos].withdraw(amt))
            {
                W[toPos].load(amt);
                cout << "Transfer Successful!\n";
            }
        }



        else if(ch == 7)
        {
            cout << "Exiting Program...\n";
            break;
        }


        else
        {
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}
