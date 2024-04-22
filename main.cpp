#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Node.h"
#include "Splay.h"
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
    std::string interest;
    std::cin >> interest;
    std::string year;
    std::cin >> year;
    std::vector<Node> data = Node::readFile(csv, interest);
    // deallocate vector memory
    csv.clear();
    // splay testing - delete later
    Splay splay;
    for (const Node& val : data){
        if (val.year == year){ // if the year is our target
            splay.insert(val.country, val.data);
        }
    }
    splay.levelOrder();
    // to recreate the tree with a different data of interest, we need to do data = Node::readFile(csv, interest) again
    splay.deleteTree();
}
