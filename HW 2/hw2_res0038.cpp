//Evan Sheehan
//res0038
//hw2_res0038.cpp
//Compile with G++

/* Sources
//Chapter 1.pdf p28-29
//https://stackoverflow.com/questions/30250934/how-to-end-c-code
//http://www.cplusplus.com/reference/ios/ios_base/setf/ */

#include <iostream>
using namespace std;

double loanAmount;
double interestRate;
double interestSum;
double interest;
double monthlyPay;
double balance;
double principal;
int month = 0;

double calcBalance(double balanceIn, double principalIn);
double calcInterest(double balanceIn, double interestRateIn);
double calcPrincipal(double monthlyPayIn, double interestIn, double balanceIn);
double calcMonthlyPay(double monthlyPayIn, double balanceIn, double interestIn);

int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Loan Amount: ";
    cin >> loanAmount;
    cout << "Interest Rate (% per year): ";
    cin >> interestRate;
    cout << "Monthly Payments: ";
    cin >> monthlyPay;

    balance = loanAmount;
    interestRate /= 12;

    if (calcInterest(balance, interestRate) > monthlyPay) {
        cout << "You will never pay off your interest at this rate! Increase your monthly payment." << endl;
        return 0;
    }

    cout << "******************************************************" << endl;
    cout << "\t\tAmortization Table" << endl;
    cout << "******************************************************" << endl;
    cout << "Month\tBalance Payment Rate\tInterest Principal" << endl;

    cout << month++ << "\t$" << balance << " N/A\tN/A\tN/A\t N/A" << endl;

    while (balance > 0) {
        interest = calcInterest(balance, interestRate);
        principal = calcPrincipal(monthlyPay, interest, balance);
        monthlyPay = calcMonthlyPay(monthlyPay, balance, interest);
        balance = calcBalance(balance, principal);
        interestSum += interest;

        cout << month << "\t$" << balance << " $" << monthlyPay << "\t";
        cout.unsetf(ios::fixed);
        cout.unsetf(ios::showpoint);
        cout << interestRate;
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout << "\t$" << interest << "\t$" << principal << endl;

        month++;
    }
    cout << "******************************************************" << endl;
    cout << "\nIt takes " << --month << " months to pay off the loan." << endl;
    cout << "Total interest paid is: $" << interestSum << endl;

    return 0;
}

double calcBalance(double balanceIn, double principalIn) {
    balanceIn -= principalIn;
    if (balanceIn < 0) {
        balanceIn = 0;
    }
    return balanceIn;
}

double calcInterest(double balanceIn, double interestRateIn) {
    double interestOut = balanceIn * (interestRateIn * 0.01);
    return interestOut;
}

double calcPrincipal(double monthlyPayIn, double interestIn, double balanceIn) {
    double principalOut;
    if (balanceIn < monthlyPayIn) {
        principalOut = balanceIn;
    }
    else {
        principalOut = monthlyPayIn - interestIn;
    }
    return principalOut;
}

double calcMonthlyPay(double monthlyPayIn, double balanceIn, double interestIn) {
    if (balanceIn < monthlyPayIn) {
        monthlyPayIn = balanceIn + interestIn;
    }
    return monthlyPayIn;
}
