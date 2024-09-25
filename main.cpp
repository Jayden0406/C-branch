#include <iostream>
using namespace std;

int main() {
  // Calculate the number of customers purchasing energy drinks
  int energyDrinkCustomers = 0.15 * 16500;
  cout << "Approximate number of customers purchasing one or more energy drinks: "
       << energyDrinkCustomers << endl;

  // Calculate the number of customers preferring citrus-flavored energy drinks
  int citrusDrinkCustomers = 0.58 * 16500;
  cout << "Approximate number of customers preferring citrus-flavored energy "
       << "drinks: " << citrusDrinkCustomers << endl;

  return 0;
}
