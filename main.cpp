#include <iostream>
#include <cmath>
// Function prototypes with preconditions and postconditions as comments

// Pre: x1, y1, x2, y2 are integers representing coordinates of two points on the Cartesian plane
// Post: Returns the distance between (x1, y1) and (x2, y2)
double calcDistance(int x1, int y1, int x2, int y2);

// Pre: x_center, y_center, x_point, y_point are integers representing the center and a point on the circumference of a circle
// Post: Returns the radius of the circle
double calcRadius(int x_center, int y_center, int x_point, int y_point);

// Pre: r is a double representing the radius of the circle
// Post: Returns the circumference of the circle
double calcCircumference(double r);

// Pre: r is a double representing the radius of the circle
// Post: Returns the area of the circle
double calcArea(double r);

int main() {
    // IPO chart:
    // Input: Center point coordinates (x_center, y_center) and point on circumference coordinates (x_point, y_point)
    // Processing: Calculate distance, radius, circumference, and area of the circle
    // Output: Display the radius, circumference, and area of the circle

    int x_center, y_center, x_point, y_point;
    double radius, circumference, area;

    // Accept user input for center and point coordinates
    std::cout << "Enter the coordinates of the center of the circle (x y): ";
    std::cin >> x_center >> y_center;

    std::cout << "Enter the coordinates of a point on the circumference of the circle (x y): ";
    std::cin >> x_point >> y_point;

    // Calculate radius
    radius = calcRadius(x_center, y_center, x_point, y_point);

    // Calculate circumference
    circumference = calcCircumference(radius);

    // Calculate area
    area = calcArea(radius);

    // Display output
    std::cout << "Radius of the circle: " << radius << std::endl;
    std::cout << "Circumference of the circle: " << circumference << std::endl;
    std::cout << "Area of the circle: " << area << std::endl;

    return 0;
}

double calcDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double calcRadius(int x_center, int y_center, int x_point, int y_point) {
    return calcDistance(x_center, y_center, x_point, y_point);
}

double calcCircumference(double r) {
    return 2 * 3.1416 * r;
}

double calcArea(double r) {
    return 3.1416 * r * r;
}
