#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  // Define variables
  double gas = 20;
  double miles_in_town = 23.5;
  double miles_on_highway = 28.9;
  double distance_in_town;
  double distance_on_highway;

  // Calculate distances
  distance_in_town = gas * miles_in_town;
  distance_on_highway = gas * miles_on_highway;

  // Display results
  cout << "Distance in town: " << fixed << setprecision(1) << distance_in_town << " miles" << endl;
  cout << "Distance on highway: " << fixed << setprecision(1) << distance_on_highway << " miles" << endl;

  return 0;
}
