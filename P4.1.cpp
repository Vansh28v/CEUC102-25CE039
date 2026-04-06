#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;
    void resize(int newCap) {
        int* temp = new int[newCap];
        for(int i=0;i<size;i++) temp[i]=arr[i];
        delete[] arr;
        arr=temp;
        capacity=newCap;
    }
public:
    DynamicArray() { size=0; capacity=2; arr=new int[capacity]; }
    void insertEnd(int val) {
        if(size==capacity) resize(capacity*2);
        arr[size++]=val;
    }
    void deleteAt(int idx) {
        if(idx<0||idx>=size) return;
        for(int i=idx;i<size-1;i++) arr[i]=arr[i+1];
        size--;
    }
    void display() {
        for(int i=0;i<size;i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }
    ~DynamicArray() { delete[] arr; }
};

int main() {
    DynamicArray da;
    da.insertEnd(10);
    da.insertEnd(20);
    da.insertEnd(30);
    da.insertEnd(40);
    da.insertEnd(50);
    da.display();
    da.deleteAt(0);
    da.deleteAt(2);
    da.deleteAt(7);

    return 0;
}
