#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // File name
    string filename = "output.txt";

    // Vector to store lines from the file
    vector<string> lines;

    // Read lines from the file
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (!line.empty()) {
                lines.push_back(line);
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
        return 1;
    }

    // Process and print the lines in the desired format
    for (const auto& line : lines) {
        // Split the line by space
        size_t spacePos = line.find(' ');
        string name = line.substr(0, spacePos);
        string grade = line.substr(spacePos + 1); // Extract the grade

        // Print in the desired format
        cout << "Name: " << name << ", Grade: " << grade << endl;
    }

    return 0;
}
