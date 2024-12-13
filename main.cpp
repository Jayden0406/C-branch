#ifndef BASICT_SHAPE_H
#define BASICT_SHAPE_H

#include <string>

class BasicShape {
private:
    double area;
    std::string name;

public:
    BasicShape() : area(0.0), name("") {}

    virtual ~BasicShape() = default;

    // Getter for area
    double getArea() const {
        return area;
    }

    // Setter for area
    void setArea(double a) {
        area = a;
    }

    // Getter for name
    std::string getName() const {
        return name;
    }

    // Setter for name
    void setName(const std::string& n) {
        name = n;
    }

    // Pure virtual function to be implemented by derived classes
    virtual void calcArea() = 0;
};

#endif // BASICT_SHAPE_H
#ifndef CIRCLE_H
#define CIRCLE_H

#include "BasicShape.h"
#include <cmath>

class Circle : public BasicShape {
private:
    double xCenter;
    double yCenter;
    double radius;

public:
    // Constructor
    Circle(double x, double y, double r, const std::string& n = "Circle")
        : xCenter(x), yCenter(y), radius(r) {
        setName(n);
        calcArea();
    }

    // Getter for xCenter
    double getXCenter() const {
        return xCenter;
    }

    // Getter for yCenter
    double getYCenter() const {
        return yCenter;
    }

    // Getter for radius
    double getRadius() const {
        return radius;
    }

    // Override the calcArea function
    void calcArea() override {
        double area = M_PI * radius * radius;
        setArea(area);
    }
};

#endif // CIRCLE_H
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "BasicShape.h"

class Rectangle : public BasicShape {
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle(double l, double w, const std::string& n = "Rectangle")
        : length(l), width(w) {
        setName(n);
        calcArea();
    }

    // Getter for length
    double getLength() const {
        return length;
    }

    // Getter for width
    double getWidth() const {
        return width;
    }

    // Override the calcArea function
    void calcArea() override {
        double area = length * width;
        setArea(area);
    }
};

#endif // RECTANGLE_H
#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle {
public:
    // Constructor
    Square(double s, const std::string& n = "Square")
        : Rectangle(s, s, n) {}

    // Getter for side
    double getSide() const {
        return getLength();  // Since length and width are the same in Square
    }
};

#endif // SQUARE_H
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

int main() {
    // Create an array of BasicShape pointers
    BasicShape* shapes[5];

    // Fill the array with two Rectangle objects, two Circle objects, and one Square object
    shapes[0] = new Rectangle(10, 5, "Rectangle 1");
    shapes[1] = new Rectangle(8, 4, "Rectangle 2");
    shapes[2] = new Circle(0, 0, 7, "Circle 1");
    shapes[3] = new Circle(2, 3, 4, "Circle 2");
    shapes[4] = new Square(6, "Square 1");

    // Loop through the array and display the name and area of each shape
    for (int i = 0; i < 5; ++i) {
        std::cout << "Shape: " << shapes[i]->getName() << ", Area: " << shapes[i]->getArea() << std::endl;
    }

    // Clean up dynamic memory
    for (int i = 0; i < 5; ++i) {
        delete shapes[i];
    }

    return 0;
}
