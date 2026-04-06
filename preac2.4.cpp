#include<iostream>
#include<string>
using namespace std;
class Store{

public:
    int no_item=50;
    string item_id;
    string item_name;
    float item_price;

    void add_data(){
    cout<<"Enter item name:"<<endl;
    cin>> item_name;
    cout<<"Enter item ID:"<<endl;
    cin>> item_id;
    cout<<"Enter item price:"<<endl;
    cin>> item_price;
    }
    void display_data(){
    cout<<"Item name is: "<<item_name<<endl;
    cout<<"Item id is: "<<item_id<<endl;
    cout<<"Price of this item is: "<<item_price<<endl;
    cout<<"Total no. of item:"<<no_item<<endl;
    }

    void sell_item(){
    no_item--;
    }

    void add_item(){
        no_item++;
    }
}s;

    int main(){
        int choice;

            cout<<"1 for add item"<<endl;
            cout<<"2 for display item details"<<endl;
            cout<<"3 for sell item"<<endl;
            cout <<"0 for Exit"<<endl;
            do{
            cin>>choice;

            switch(choice){
        case 1:
            s.add_data();
            break;
        case 2:
            s.display_data();
            break;
        case 3:
            s.sell_item();
            break;
        case 0:
            break;
        default:
            cout<<"enter valid choice"<<endl;
            }
        }
        while(choice!=0);
        return 0;
    }
