#include <iostream>
#include <vector>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }

    void displayPerson()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Intermediate Class
class Employee : public Person
{
protected:
    int empID;

public:
    Employee(string n, int a, int id) : Person(n, a)
    {
        empID = id;
    }

    void displayEmployee()
    {
        displayPerson();
        cout << "Employee ID: " << empID << endl;
    }

    int getID()
    {
        return empID;
    }
};

class Manager : public Employee
{
    string department;

public:
    Manager(string n, int a, int id, string dept)
        : Employee(n, a, id)
    {
        department = dept;
    }

    void displayManager()
    {
        displayEmployee();
        cout << "Department: " << department << endl;
        cout << "-----------------------------" << endl;
    }

    string getDept()
    {
        return department;
    }

    void updateDept(string dept)
    {
        department = dept;
    }
};

int main()
{
    int n;
    cout << "Enter number of managers: ";
    cin >> n;

    vector<Manager> managers;

    for(int i = 0; i < n; i++)
    {
        string name, dept;
        int age, id;

        cout << "\nEnter details of Manager " << i+1 << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Employee ID: ";
        cin >> id;
        cout << "Department: ";
        cin >> dept;

        managers.push_back(Manager(name, age, id, dept));
    }

    // Display all
    cout << "\n--- Manager Details ---\n";
    for(int i = 0; i < managers.size(); i++)
    {
        managers[i].displayManager();
    }

    
    int searchID;
    cout << "\nEnter Employee ID to search: ";
    cin >> searchID;

    for(int i = 0; i < managers.size(); i++)
    {
        if(managers[i].getID() == searchID)
        {
            cout << "\nManager Found:\n";
            managers[i].displayManager();
        }
    }

    Manager staticManagers[2] = {
        Manager("Amit", 40, 101, "HR"),
        Manager("Sara", 38, 102, "Finance")
    };

    cout << "\n--- Static Managers ---\n";
    for(int i = 0; i < 2; i++)
    {
        staticManagers[i].displayManager();
    }

    return 0;
}