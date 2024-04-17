#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Data.h"

int main() {
    // open csv file
    std::ifstream file("owid-co2-data.csv");

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // store data in vector of vectors using getline
    std::string line;
    std::vector<std::vector<std::string>> csv;

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string column;

        while (std::getline(ss, column, ',')) {
            row.push_back(column);
        }

        csv.push_back(row);
    }

    file.close();

    std::vector<Data> data = Data::readFile(csv);

    // deallocate vector memory
    csv.clear();
}

