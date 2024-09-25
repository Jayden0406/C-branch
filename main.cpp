#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  // Declare variables
  double principal, rate, balance;
  int timesCompounded;

  // Get user input
  cout << "Enter the principal amount: ";
  cin >> principal;
  cout << "Enter the interest rate (as a decimal): ";
  cin >> rate;
  cout << "Enter the number of times interest is compounded per year: ";
  cin >> timesCompounded;

  // Calculate the balance after one year
  balance = principal * pow(1 + (rate / timesCompounded), timesCompounded);

  // Display the report
  cout<<"Interest Rate: "<<rate*100<<"%"<<endl;
  cout << fixed << setprecision(2);
  cout << "\n----------------------------------------\n";
  cout << "Interest Report\n";
  cout << "----------------------------------------\n";
  cout << "Principal: $" << fixed << setprecision(2) << principal << endl;
  cout << "Interest Rate: " << rate * 100 << "%" << endl;
  cout << "Times Compounded: " << timesCompounded << endl;
  cout << "Amount in savings year: $" << fixed << setprecision(2) << balance << endl;
  cout << "----------------------------------------\n";

  return 0;
}
