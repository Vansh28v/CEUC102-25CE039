#include<iostream>
#include<string>

using namespace std;

class Rectangle
{

private:

     int rectangle_id;
     double lenght;
     double width;
     double Area;
     double Perimeter;

public:

    void create(int x);
    void update();
    void display();
    double area();
    double perimeter();
    bool isSquare();

    int getID();
    int findRect();
};

void Rectangle::create(int x)
{
    rectangle_id = x;

    cout<<"Enter the lenght of rectangle:";
    cin>>lenght;

    cout<<"Enter the width of rectangle:";
    cin>>width;

    if(lenght<0 || width<0)
    {
        cout<<"Invalid value inputs!\n"<<endl;
        cout<<"Setting default dimensions 1x1!"<<endl;

        lenght=1;
        width=1;
    }
}

void Rectangle::update()
{
    double l;
    double w;

    cout<<"Enter new lenght:";
    cin>>l;

    cout<<"Enter new width:";
    cin>>w;

    if(l>0 && w>0)
    {
        cout<<"";

        lenght=l;
        width=w;
    }

    else
    {
        cout<<"Inalid! values"<<endl;
    }
}

void Rectangle::display()
{
    cout<<"Rectangle ID :"<< rectangle_id<<endl;
    cout<<"Lenght :"<< lenght<<endl;
    cout<<"Width :"<< width<<endl;
    cout<<"Area :"<< Area<<endl;
    cout<<"Perimeter :"<< Perimeter<<endl;

     if(isSquare())
     {
        cout<<"\nShape: Square";
     }

     else
     {
        cout<<"\nShape: Rectangle";
     }

    cout<<endl;
}

double Rectangle::area()
{
    return lenght*width;
}

double Rectangle::perimeter()
{
    return 2*(lenght+width);
}

int Rectangle::getID()
{
    return rectangle_id;
}
bool Rectangle::isSquare()
{
    return lenght==width;
}

int findRect(Rectangle R[], int last, int id)
{
    for(int i=0;i<last;i++)
        if(R[i].getID()==id)
            return i;

    return -1;
}


int main()
{
   Rectangle R[20];
   int last = 0;
   int choice;

   while(true)
   {
     cout<<"Welcome to rectangle management system!\n"<<endl;
     cout<<"----RECTANGLE SYSTEM MENU----\n"<<endl;
     cout<<"Create shape:\n"<<endl;
     cout<<"Update shape:\n"<<endl;
     cout<<"Display shape details:\n"<<endl;
     cout<<"Exit:\n"<<endl;
     cout<<"Enter your choice!:";
     cin>>choice;

     if(choice==1)
        {
            int id;
            cout<<"Enter ID: ";
            cin>>id;

            if(findRect(R,last,id)!=-1)
            {
                cout<<"Already exists\n";
                continue;
            }

            R[last].create(id);
            last++;
        }

        else if(choice==2)
        {
            int id;
            cin>>id;

            int p=findRect(R,last,id);

            if(p==-1)
            {
                cout<<"Not found\n";
                continue;
            }

            R[p].update();
        }

        else if(choice==3)
        {
            int id;
            cin>>id;

            int p=findRect(R,last,id);

            if(p==-1)
            {
                cout<<"Not found\n";
                continue;
            }

            R[p].display();
        }

        else
        {
            break;
        }

   }

   return 0;
}
