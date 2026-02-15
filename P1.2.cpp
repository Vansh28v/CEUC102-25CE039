#include<iostream>
#include<string>

using namespace std;

class Library
{
private:

    int Book_id;
    string Book_name;
    string Author_name;
    int copies;
    bool is_Unavailable;

public:

    void create(int id);
    void display();
    bool addcopies(int n);
    bool issuebook();
    bool returnbook();
    bool unavailable();
    bool available();

    int getID();
    int findwallet();
};

void Library::create(int id)
{
    Book_id = id;

    cout<<"Enter the Book name:";
    cin.ignore();
    getline(cin,Book_name);

    cout<<"Enter the Author's name:";
    getline(cin,Author_name);

    cout<<"Enter the number of copies:";
    cin>>copies;

    is_Unavailable = false;

    cout<<"E-wallet created successfully!";

}

void Library::display()
{
    cout<<"Enter Wallet Credential's :"<<endl;
    cout<<"Book ID :" << Book_id<<endl;
    cout<<"Book Name :"<< Book_name<<endl;
    cout<<"Author Name :"<< Author_name<<endl;
    cout<<"Copies :"<< copies<<endl;
    cout<<"Status:"<< (is_Unavailable ? "Unavailable" : "Available")<<endl;
}

bool Library::addcopies(int n)
{
    if(n<=0)
    {
        cout<<"Invalid!, Enter valid Copy number!"<<endl;
        return false;
    }

    copies +=n;

    cout<<"Copies, Added successfully!"<<endl;
    return true;
}

bool Library::issuebook()
{
    if(copies<= 0)
    {
        cout<<"Invalid!, Enter valid book copies!"<<endl;
        return false;
    }

    if(is_Unavailable)
    {
        cout<<"Sorry! Book is Unavailable"<<endl;
        return false;
    }

    copies--;
    cout<<"Book issued successfully!"<<endl;
    return true;
}

bool Library::returnbook()
{
    copies ++;
    cout<<"Book returned successfully!"<<endl;
    return true;
}

bool Library::unavailable()
{
    if(is_Unavailable)
    {
        cout<<"Book is already Unavailable!";
        return false;
    }

    is_Unavailable = true;
    cout<<"Book is Unavailable!";
    return true;
}

bool Library::available()
{
    if(!is_Unavailable)
    {
      cout<<"Book is already available!";
      return false;
    }

    is_Unavailable = false;
    cout<<"Book is available!";
    return true;
}

int Library::getID()
{
    return Book_id;
}

int findwallet(Library L[], int last, int id)
{
    for(int i=0; i<last; i++)
    {
        if(L[i].getID()== id)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    Library L[20];
    int last= 0;
    int choice;

    while(true)
    {
        cout<<"----- Welcome! to the E-Library Management System-----\n"<<endl;
        cout<<"----- E-LIBRARY MENU DASHBOARD-----\n"<<endl;
        cout<<"1.Create Library Wallet:\n"<<endl;
        cout<<"2.Issue books:\n"<<endl;
        cout<<"3.Return books:\n"<<endl;
        cout<<"4.Add copies:\n"<<endl;
        cout<<"5.Display Wallet:\n"<<endl;
        cout<<"6.Mark Available:\n"<<endl;
        cout<<"7.Mark Unavailable:\n"<<endl;
        cout<<"8.EXIT\n"<<endl;
        cout<<"Enter your choice:\n";
        cin>>choice;


    if(choice==1)
    {
        if(last>=20)
        {
            cout<<"The E-wallet access is not in limit!"<<endl;
        }

        int id;

        cout<<"Enter the Book ID:"<<endl;
        cin>>id;

        if(findwallet(L,last,id)!=-1)
        {
            cout<<"Book ID is already existing!\n";
            continue;
        }

        L[last].create(id);
        last++;
    }

    else if(choice==2)
    {
        int id;

        cout<<"Enter the Book ID:"<<endl;
        cin>>id;

        int pos = findwallet(L,last,id);

        if(pos==-1)
        {
            cout<<"Book ID not found!"<<endl;
            continue;
        }

        L[pos].issuebook();
    }

    else if(choice==3)
    {
        int id;

        cout<<"Enter the Book ID:"<<endl;
        cin>>id;

        int pos = findwallet(L,last,id);

        if(pos==-1)
        {
            cout<<"Book ID not found!"<<endl;
            continue;
        }

        L[pos].returnbook();
    }

    else if(choice==4)
    {
        int id;
        int n;

        cout<<"Enter the Book ID:"<<endl;
        cin>>id;

        int pos = findwallet(L,last,id);

        if(pos==-1)
        {
            cout<<"Book ID not found!"<<endl;
            continue;
        }

        cout<<"Enter the number of copies:"<<endl;

        L[pos].addcopies(n);
    }

    else if(choice==5)
    {
        int id;

        cout<<"Enter the Book ID:"<<endl;
        cin>>id;

        int pos = findwallet(L,last,id);

        if(pos==-1)
        {
            cout<<"Book ID not found!"<<endl;
            continue;
        }

        L[pos].display();
    }

    else if(choice==6)
    {
        int id;

        cout<<"Enter the Book ID:"<<endl;
        cin>>id;

        int pos = findwallet(L,last,id);

        if(pos==-1)
        {
            cout<<"Book ID not found!"<<endl;
            continue;
        }

        L[pos].unavailable();

    }

    else if(choice==7)
    {
        int id;

        cout<<"Enter the Book ID:"<<endl;
        cin>>id;

        int pos = findwallet(L,last,id);

        if(pos==-1)
        {
            cout<<"Book ID not found!"<<endl;
            continue;
        }

        L[pos].available();
    }

    else if(choice==8)
    {
        cout<<"Exiting program..."<<endl;
        break;
    }

    else
    {
        cout<<"Invalid input!"<<endl;
    }

    }

    return 0;
}

