#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  // Declare variables for the original recipe quantities
  double sugar = 1.5;
  double butter = 1;
  double flour = 2.75;

  // Declare variables for the user's desired cookie quantity and the calculated ingredient quantities
  int desired_cookies;
  double required_sugar, required_butter, required_flour;

  // Get the user's desired number of cookies
  cout << "How many cookies would you like to make? ";
  cin >> desired_cookies;

  // Calculate the required ingredient quantities
  required_sugar = (sugar / 48) * desired_cookies;
  required_butter = (butter / 48) * desired_cookies;
  required_flour = (flour / 48) * desired_cookies;

  // Display the required ingredient quantities
  cout << "\nTo make " << desired_cookies << " cookies, you will need:\n";
  cout << "Sugar: " << fixed << setprecision(2) << required_sugar << " cups\n";
  cout << "Butter: " << fixed << setprecision(2) << required_butter << " cups\n";
  cout << "Flour: " << fixed << setprecision(2) << required_flour << " cups\n";

  return 0;
}