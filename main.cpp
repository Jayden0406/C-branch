#include <iostream>
#include <string>

double calculate(int num1, int num2, char op) {
    switch(op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if(num2 == 0) {
                std::cout << "Error! Division by zero is not allowed.\n";
                return 0; // Or throw an exception
            } else {
                return static_cast<double>(num1) / num2;
            }
        default:
            std::cout << "Error! Unsupported operator.\n";
            return 0;
    }
}

int main() {
    int num1, num2;
    char op;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> op;

    double result = calculate(num1, num2, op);
    std::cout << num1 << " " << op << " " << num2 << " = " << result << std::endl;

    return 0;
}
