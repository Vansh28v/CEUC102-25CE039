#include<iostream>
#include<string>

using namespace std;

class Bank
{
private:

    long long Bank_acct_no;
    string user_name;
    long long balance;
    bool isfrozen;

public:

    void create(int id);
    void display();
    bool load(long double amt);
    bool withdrawl(long double amt);
    bool freeze();
    bool unfreeze();

    long long getNO();
    long long getbalance();
    bool frozen();
    int findwallet();
};

void Bank::create(int id)
{
    Bank_acct_no = id;

    cout<<"Enter the bank account holder's name:"<<endl;
    cin.ignore();
    getline(cin , user_name);

    cout<<"Enter the Bank balance :";
    cin>> balance;

    isfrozen = false;

    cout<<"Bank Account created successfully!\n"<<endl;
}

void Bank::display()
{
    cout<<"----ACCOUNT CREDENTIALS----\n"<<endl;
    cout<<"Account number  :"<< Bank_acct_no<<endl;
    cout<<"Account Holder's name :"<< user_name<<endl;
    cout<<"Bank balance :"<< balance<<endl;
    cout<<"Status :"<< (isfrozen ? "Frozen" : "Active")<<endl;
}

bool Bank::load(long double amt)
{
    if(isfrozen)
    {
        cout<<"Account Frozen! Unable to load money";
        return false;
    }

    if(balance < 0)
    {
      cout<<"Enter valid Value amount!";
      return false;
    }

    balance += amt;
    cout<<"Money loaded successfully!";

    return true;
}

bool Bank::withdrawl(long double amt)
{
    if(isfrozen)
    {
        cout<<"Account Frozen! Unable to withdrawl money";
        return false;
    }

    if(balance < 0)
    {
      cout<<"Enter valid Value amount!";
      return false;
    }

    if(amt <0)
    {
      cout<<"Insufficient balance!";
      return false;
    }

    balance -= amt;
    cout<<"Money withdrawled successfully!";

    return true;
}

bool Bank::freeze()
{
    if(isfrozen)
    {
        cout<<"Account is Already Frozen!";
        return false;
    }

    isfrozen = true;
    cout<<"Account Frozen successfully!";
    return true;
}

bool Bank::unfreeze()
{
    if(!isfrozen)
    {
        cout<<"Account is already Active";
        return false;
    }

    isfrozen = false;
    cout<<"Account Unfrozen successfully!";
    return true;
}

long long Bank::getNO()
{
    return Bank_acct_no;
}

long long Bank::getbalance()
{
    return balance;
}

bool Bank::frozen()
{
    return isfrozen;
}

int findwallet( Bank B[], int last, int id)
{

  for(int i=0; i<last; i++)
  {
      if( B[i].getNO() == id)
      {
          return i;

      }
  }

   return -1;
}


int main()
{
    Bank B[20];
    int last = 0;
    int ch;

    while(true)
    {
       cout << "\n====== BANK MENU ======\n";
       cout << "1. Create Account\n";
       cout << "2. Load Money\n";
       cout << "3. Withdrawl Money\n";
       cout << "4. Check Balance\n";
       cout << "5. Freeze Account\n";
       cout << "6. Unfreeze Account\n";
       cout << "7. Exit\n";

       cout << "Enter Choice --> ";
       cin >> ch;

       if(ch==1)
       {
           if(last >= 20)
            {
            cout << "Maximum Accounts Limit Reached!\n";
            continue;
            }

            int id;
            cout << "Enter Bank account no: --> ";
            cin >> id;
            if(findwallet(B, last, id) != -1)
            {
            cout << "Account ID Already Exists!\n";
            continue;
            }

            B[last].create(id);
            last++;
       }

       else if(ch==2)
       {
            int id;
            double amt;
            cout << "Enter Bank Account no --> ";
            cin >> id;
            int pos = findwallet(B, last, id);
            if(pos == -1)
            {
            cout << "Account Not Found!\n";
            continue;
            }
            cout << "Enter Amount --> ";
            cin >> amt;
            B[pos].load(amt);
       }

       else if(ch==3)
       {
           int id;
           double amt;
           cout << "Enter Bank Account no --> ";
           cin>> id;
           int pos = findwallet(B, last, id);
           if(pos == -1)
           {
           cout << "Account Not Found!\n";
           continue;
           }
           cout << "Enter Amount --> ";
           cin >> amt;
            B[pos].withdrawl(amt);
       }

       else if(ch==4)
       {
           int id;
           cout << "Enter Account number --> ";
           cin >> id;
           int pos = findwallet(B, last, id);
           if(pos == -1)
           {
                cout << "Wallet Not Found!\n";
                continue;
            }
            B[pos].display();
       }

       else if(ch ==5)
       {
        int id;
        cout << "Enter Account number --> ";
        cin >> id;
        int pos = findwallet(B, last, id);
        if(pos == -1)
        {

             cout << "Wallet Not Found!\n";
             continue;
        }
         B[pos].freeze();
       }

        else if(ch ==6)
        {
        int id;
        cout << "Enter Account number --> ";
        cin >> id;
        int pos = findwallet(B, last, id);
        if(pos == -1)
        {

             cout << "Account Not Found!\n";
             continue;

        }
        B[pos].unfreeze();
        }

       else if(ch == 7)
       {
           cout<<"Exiting program...";
           break;
        }

        else
        {
             cout << "Invalid Choice!\n";
        }

    }

    return 0;
}
