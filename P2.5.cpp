#include <iostream>
#include <cmath>
using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;

public:
    // Default Constructor
    Loan() {
        loanID = 0;
        applicantName = "Unknown";
        loanAmount = 0.0;
        annualInterestRate = 0.0;
        tenureMonths = 0;
    }

    // Parameterized Constructor
    Loan(int id, string name, double amount, double rate, int tenure) {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = rate;
        tenureMonths = tenure;
    }

    double calculateEMI() {
        double monthlyRate = annualInterestRate / (12 * 100);
        double EMI = (loanAmount * monthlyRate * pow(1 + monthlyRate, tenureMonths)) /
                     (pow(1 + monthlyRate, tenureMonths) - 1);
        return EMI;
    }

    void displayDetails() {
        cout << "\nLoan Details:\n";
        cout << "Loan ID: " << loanID << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Loan Amount: " << loanAmount << endl;
        cout << "Annual Interest Rate (%): " << annualInterestRate << endl;
        cout << "Tenure (months): " << tenureMonths << endl;
        cout << "Monthly EMI: " << calculateEMI() << endl;
    }
};

int main() {

    Loan loan1;
    cout << "Default Loan Object:";
    loan1.displayDetails();

    // Using parameterized constructor
    Loan loan2(101, "Aviroop Shi", 500000, 7.5, 60);
    cout << "\nParameterized Loan Object:";
    loan2.displayDetails();

    return 0;
}
