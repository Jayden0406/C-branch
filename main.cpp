#include <iostream>

// Function to get input from user
void getInput(float &currentPrice, float &priceOneYearAgo, float &priceTwoYearsAgo) {
    std::cout << "Enter the current price of the item: ";
    std::cin >> currentPrice;
    std::cout << "Enter the price of the item one year ago: ";
    std::cin >> priceOneYearAgo;
    std::cout << "Enter the price of the item two years ago: ";
    std::cin >> priceTwoYearsAgo;
}

// Function to calculate inflation rates
void calculateInflation(float currentPrice, float priceOneYearAgo, float priceTwoYearsAgo, float &inflationRate1, float &inflationRate2) {
    inflationRate1 = (currentPrice - priceOneYearAgo) / priceOneYearAgo;
    inflationRate2 = (priceOneYearAgo - priceTwoYearsAgo) / priceTwoYearsAgo;
}

// Function to output results
void outputResults(float inflationRate1, float inflationRate2) {
    std::cout << "Inflation rate for the first year: " << inflationRate1 << std::endl;
    std::cout << "Inflation rate for the second year: " << inflationRate2 << std::endl;
    if (inflationRate1 > inflationRate2) {
        std::cout << "Inflation trend: Decreasing" << std::endl;
    } else {
        std::cout << "Inflation trend: Increasing" << std::endl;
    }
}

int main() {
    float currentPrice, priceOneYearAgo, priceTwoYearsAgo, inflationRate1, inflationRate2;

    // Get input from user
    getInput(currentPrice, priceOneYearAgo, priceTwoYearsAgo);

    // Calculate inflation rates
    calculateInflation(currentPrice, priceOneYearAgo, priceTwoYearsAgo, inflationRate1, inflationRate2);

    // Output results
    outputResults(inflationRate1, inflationRate2);

    return 0;
}
