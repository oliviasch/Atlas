#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Node.h"
#include "Splay.h"
#include "RBTree.h"
#include <chrono>
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
    std::cout << "Enter the data of interest:" << std::endl;
    std::string interest;
    std::cin >> interest;
    std::cout << "Enter the year of interest: " << std::endl;
    std::string year;
    std::cin >> year;
    std::vector<Node> data = Node::readFile(csv, interest);
    // deallocate vector memory
    csv.clear();
    // splay testing - delete later
    Splay splay;
    RBTree RB;
    // insertions
    auto splayStartTime = std::chrono::steady_clock::now();
    for (const Node& val : data){
        if (val.year == year){ // if the year is our target
            splay.insert(val.country, val.data);
        }
    }
    auto splayEndTime = std::chrono::steady_clock::now();
    auto splayDuration = std::chrono::duration_cast<std::chrono::microseconds>(splayEndTime - splayStartTime);
    // print timer
    std::cout << "Splay Tree insert time: " << splayDuration.count() << " microseconds" << std::endl;
    auto RBStartTime = std::chrono::steady_clock::now();
    for (const Node& val : data){
        if (val.year == year){ // if the year is our target
            RB.insert(RB.root, val.country, val.data);
        }
    }
    auto RBEndTime = std::chrono::steady_clock::now();
    auto RBDuration = std::chrono::duration_cast<std::chrono::microseconds>(RBEndTime - RBStartTime);
    // print timer
    std::cout << "Red Black tree insert time: " << RBDuration.count() << " microseconds" << std::endl;
    // searches
    std::string country;
    std::cout << "Enter the country of interst: " << std::endl;
    std::cin >> country;
    splayStartTime = std::chrono::steady_clock::now();
    splay.search(country);
    splayEndTime = std::chrono::steady_clock::now();
    splayDuration = std::chrono::duration_cast<std::chrono::microseconds>(splayEndTime - splayStartTime);
    // print timer
    std::cout << "Splay Tree search time: " << splayDuration.count() << " microseconds" << std::endl;
    RBStartTime = std::chrono::steady_clock::now();
    RB.search(RB.root, country);
    RBEndTime = std::chrono::steady_clock::now();
    RBDuration = std::chrono::duration_cast<std::chrono::microseconds>(RBEndTime - RBStartTime);
    // print timer
    std::cout << "Red Black tree insert time: " << RBDuration.count() << " microseconds" << std::endl;

    splayStartTime = std::chrono::steady_clock::now();
    splay.search(country);
    splayEndTime = std::chrono::steady_clock::now();
    splayDuration = std::chrono::duration_cast<std::chrono::microseconds>(splayEndTime - splayStartTime);
    // print timer
    std::cout << "Splay Tree search time: " << splayDuration.count() << " microseconds" << std::endl;
    RBStartTime = std::chrono::steady_clock::now();
    RB.search(RB.root, country);
    RBEndTime = std::chrono::steady_clock::now();
    RBDuration = std::chrono::duration_cast<std::chrono::microseconds>(RBEndTime - RBStartTime);
    // print timer
    std::cout << "Red Black tree insert time: " << RBDuration.count() << " microseconds" << std::endl;

    splay.deleteTree();
}
