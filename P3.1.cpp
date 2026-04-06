#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
    Employee() {
        name = "Unknown";
        basicSalary = 0;
        bonus = 1000;
    }

    Employee(string n, double salary) {
        name = n;
        basicSalary = (salary < 0) ? 0 : salary;
        bonus = 1000;
    }

    Employee(string n, double salary, double b) {
        name = n;
        basicSalary = (salary < 0) ? 0 : salary;
        bonus = (b < 0) ? 0 : b;
    }

    inline double calculateTotalSalary() {
        return basicSalary + bonus;
    }

    void updateBonus(double newBonus) {
        if (newBonus >= 0)
            bonus = newBonus;
        else
            cout << "Invalid bonus!\n";
    }

    string getGrade() {
        double total = calculateTotalSalary();
        if (total >= 100000) return "A";
        else if (total >= 50000) return "B";
        else return "C";
    }

    void display() {
        cout << "\nEmployee Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << calculateTotalSalary() << endl;
        cout << "Grade: " << getGrade() << endl;
    }
};

int main() {
    int n = 5;


    Employee* emp = new Employee[n];

    emp[0] = Employee("Jyot", 40000);
    emp[1] = Employee("Yug", 60000, 5000);
    emp[2] = Employee("Dhruv", 80000);
    emp[3] = Employee("Poojan", 120000, 15000);
    emp[4] = Employee("Dwija", 30000, 2000);

    cout << "Employee Payroll Details:\n";
    for (int i = 0; i < n; i++) {
        emp[i].display();
    }

    cout << "\nUpdating bonus for Alice...\n";
    emp[0].updateBonus(7000);
    emp[0].display();

    delete[] emp;

    return 0;
}
