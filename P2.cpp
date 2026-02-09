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

    void create();

    bool load(int);
    bool check(int);
    bool freezeAcc(int);
    bool unfreezeAcc(int);
};

void Wallet::create()
{
    cout << "Enter Wallet ID --> ";
    cin >> walletID;

    cout << "Enter Name --> ";
    cin >> userName;

    cout << "Enter Balance --> ";
    cin >> balance;

    isFrozen = false;

    cout << "Wallet Created Successfully!\n";
}

bool Wallet::load(int id)
{
    double amt;

    if(walletID == id)
    {
        if(isFrozen)
        {
            cout << "Wallet is Frozen! Cannot Load.\n";
            return true;
        }

        cout << "Enter amount --> ";
        cin >> amt;

        if(amt <= 0)
        {
            cout << "Invalid Amount\n";
            return true;
        }

        balance += amt;
        cout << "Money Loaded Successfully!\n";

        return true;
    }

    return false;
}

bool Wallet::check(int id)
{
    if(walletID == id)
    {
        cout << "\n----- Wallet Details -----\n";
        cout << "ID      : " << walletID << endl;
        cout << "Name    : " << userName << endl;
        cout << "Balance : " << balance << endl;
        cout << "Status  : " << (isFrozen ? "Frozen" : "Active") << endl;

        return true;
    }

    return false;
}

bool Wallet::freezeAcc(int id)
{
    if(walletID == id)
    {
        isFrozen = true;
        cout << "Wallet Frozen Successfully!\n";
        return true;
    }

    return false;
}

bool Wallet::unfreezeAcc(int id)
{
    if(walletID == id)
    {
        isFrozen = false;
        cout << "Wallet Unfrozen Successfully!\n";
        return true;
    }

    return false;
}

int main()
{
    Wallet W[20];

    int last = 0;
    int ch, id;

    while(true)
    {
        cout << "\n====== WALLET MENU ======\n";
        cout << "1. Create Wallet\n";
        cout << "2. Load Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Freeze Wallet\n";
        cout << "5. Unfreeze Wallet\n";
        cout << "6. Exit\n";

        cout << "Enter Choice --> ";
        cin >> ch;

        switch(ch)
        {
        case 1:

            W[last].create();
            last++;
            break;


        case 2:

            cout << "Enter Wallet ID --> ";
            cin >> id;

            for(int i = 0; i < last; i++)
            {
                if(W[i].load(id))
                    break;

                if(i == last-1)
                    cout << "ERROR: Wallet Not Found\n";
            }
            break;


        case 3:
        {
            cout << "Enter Wallet ID --> ";
            cin >> id;

            int pos = -1;

            for(int i = 0; i < last; i++)
            {
                if(W[i].check(id))
                {
                    pos = i;
                    break;
                }
            }

            if(pos == -1)
                cout << "ERROR: Wallet Not Found\n";

            break;
        }


        case 4:

            cout << "Enter Wallet ID --> ";
            cin >> id;

            for(int i = 0; i < last; i++)
            {
                if(W[i].freezeAcc(id))
                    break;

                if(i == last-1)
                    cout << "ERROR: Wallet Not Found\n";
            }
            break;


        case 5:

            cout << "Enter Wallet ID --> ";
            cin >> id;

            for(int i = 0; i < last; i++)
            {
                if(W[i].unfreezeAcc(id))
                    break;

                if(i == last-1)
                    cout << "ERROR: Wallet Not Found\n";
            }
            break;


        case 6:

            cout << "Exiting Program...\n";
            return 0;


        default:

            cout << "ERROR: Invalid Choice\n";
        }
    }

    return 0;
}
