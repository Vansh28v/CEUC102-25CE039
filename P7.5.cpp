#include <iostream>
#include <vector>
using namespace std;

class Student
{
protected:
    float marks;

public:
    Student(float m)
    {
        marks = m;
    }

    virtual char computeGrade() = 0; 

    virtual void display()
    {
        cout << "Marks: " << marks << endl;
    }

    virtual ~Student() {}
};

class Undergraduate : public Student
{
public:
    Undergraduate(float m) : Student(m) {}

    char computeGrade()
    {
        if(marks >= 75) return 'A';
        else if(marks >= 60) return 'B';
        else if(marks >= 50) return 'C';
        else return 'F';
    }

    void display()
    {
        cout << "Undergraduate -> ";
        Student::display();
        cout << "Grade: " << computeGrade() << endl;
        cout << "----------------------\n";
    }
};

class Postgraduate : public Student
{
public:
    Postgraduate(float m) : Student(m) {}

    char computeGrade()
    {
        if(marks >= 80) return 'A';
        else if(marks >= 65) return 'B';
        else if(marks >= 55) return 'C';
        else return 'F';
    }

    void display()
    {
        cout << "Postgraduate -> ";
        Student::display();
        cout << "Grade: " << computeGrade() << endl;
        cout << "----------------------\n";
    }
};

int main()
{
    vector<Student*> students;

    students.push_back(new Undergraduate(78));
    students.push_back(new Undergraduate(55));
    students.push_back(new Postgraduate(82));
    students.push_back(new Postgraduate(60));

    cout << "--- Student Records ---\n";
    for(int i = 0; i < students.size(); i++)
    {
        students[i]->display();
    }

    for(int i = 0; i < students.size(); i++)
        delete students[i];

    return 0;
}