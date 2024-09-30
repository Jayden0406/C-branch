#include <iostream>
#include <string>

int main() {
    int num1, num2;
    char op;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> op;

    switch(op) {
        case '+':
            std::cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        case '-':
            std::cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case '*':
            std::cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case '/':
            if(num2 == 0) {
                std::cout << "Error! Division by zero is not allowed.";
            } else {
                std::cout << num1 << " / " << num2 << " = " << static_cast<double>(num1) / num2;
            }
            break;
        default:
            std::cout << "Error! Unsupported operator.";
    }

    return 0;
}
