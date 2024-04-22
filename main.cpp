#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Node.h"
#include "Splay.h"
#include "RBTree.h"
void printMenu() {
    std::cout << "Analyze CO2 Emissions with Atlas" << std::endl;
    std::cout << "Enter 1 to view data specification requirements" << std::endl;
    std::cout << "Enter 2 to create a Splay and Red Black tree based on your chosen year and data category" << std::endl;
    std::cout << "Enter 3 to search a country's data based on your chosen year and data category" << std::endl;
    std::cout << "Enter 4 to search if a data point exists in your chosen year and data category" << std::endl;
    std::cout << "Enter 5 to delete the pre-existing trees (choose if interested in a new year and data category)" << std::endl;
    std::cout << "Enter 6 to exit the program" << std::endl;
}
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
    // initializes trees
    Splay splay;
    RBTree RB;
    // clion interface
    printMenu();
    std::string userInput;
    std::cin >> userInput;
    while (userInput != "6") {
        if (userInput == "1") {
            // print data categories
            std::cout << "Years can range from 1950 to 2022, inclusive" << std::endl;
            std::cout << "Data categories must be written exactly how they are below, without the number before it. For example, input 'co2_growth_abs'" << std::endl;
            std::cout << "Shorthands: 'incl' = 'including', 'excl' = 'exclucing', 'abs' = 'absolute', 'prct' = 'percentage', 'luc' = 'land-use change', 'lucf' = 'land-use change and forestry', 'cum' = 'cumulative', 'share_global' = 'share of global annual emissions', 'ghg' = 'greenhouse gas'" << std::endl;
            std::cout << "1. population, 2. gdp, 3. cement_co2, 4. cement_co2_capita, 5. co2, ";
            std::cout << "6. co2_growth_abs, 7. co2_growth_prct, 8. co2_incl_luc, 9. co2_incl_luc_growth_abs, 10. co2_incl_luc_growth_pcrt, ";
            std::cout << "11. co2_incl_luc_per_capita, 12. co2_incl_luc_per_gdp, 13. co2_incl_luc_per_unit_energy, 14. co2_per_capita, 15. co2_per_gdp, ";
            std::cout << "16. co2_per_unit_energy, 17. coal_co2, 18. coal_co2_per_capita, 19. consumption_co2, 20. consumption_co2_per_capita, ";
            std::cout << "21. consumption_co2_per_gdp, 22. cum_cement_co2, 23. cum_co2, 24. cum_co2_incl_luc, 25. cum_coal_co2, 26. cum_flaring_co2, ";
            std::cout << "27. cum_gas_co2, 28. cum_luc_co2, 29. cum_oil_co2, 30. cum_other_co2, 31. energy_per_capita, ";
            std::cout << "32. energy_per_gdp, 33. flaring_co2, 34. flaring_co2_per_capita, 35. gas_co2, 36. gas_co2_per_capita, ";
            std::cout << "37. ghg_ecl_lucf_per_capita, 38. ghg_per_capita, 39. land_use_change_co2, 40. land_use_change_co2_per_capita, ";
            std::cout << "41. methane, 42. methane_per_capita, 43. nitrous_oxide, 44. nitrous_oxide_per_capita, 45. oil_co2, ";
            std::cout << "46. oil_co2_per_capita, 47. other_co2_per_capita, 48. other_industry_co2, 49. primary_energy_consumption, ";
            std::cout << "50. share_global_cement_co2, 51. share_global_co2, 52. share_global_co2_incl_luc, 53. share_global_coal_co2, ";
            std::cout << "54. share_global_cum_cement_co2, 55. share_global_cum_co2, 56. share_global_cum_co2_incl_luc, 57. share_global_cum_coal_co2, ";
            std::cout << "58. share_global_cum_flaring_co2, 59. share_global_cum_gas_co2, 60. share_global_cum_luc_co2, 61. share_global_cum_oil_co2, ";
            std::cout << "62. share_global_cum_other_co2, 63. share_global_flaring_co2, 64. share_global_gas_co2, 65. share_global_luc_co2, ";
            std::cout << "66. share_global_oil_co2, 67. share_global_other_co2, 68. share_of_temperature_change_from_ghg, 69. temperature_change_from_ch4, ";
            std::cout << "70. temperature_change_from_co2, 71. temperature_change_from_ghg, 72. temperature_change_from_n2o, 73. total_ghg, ";
            std::cout << "74. total_ghg_excl_lucf, 75. trade_co2" << std::endl;
        }
        else if (userInput == "2") {
            std::cout << "Enter the data category of interest: " << std::endl;
            std::string interest;
            std::cin >> interest;
            std::cout << "Enter the year of interest: " << std::endl;
            std::string year;
            std::cin >> year;
            std::vector<Node> data = Node::readFile(csv, interest);
            // splay insertions
            auto splayInsertStart = std::chrono::steady_clock::now();
            for (const Node& val : data){
                if (val.year == year){ // if the year is our target
                    splay.insert(val.country, val.data);
                }
            }
            auto splayInsertEnd = std::chrono::steady_clock::now();
            auto splayInsertTime = std::chrono::duration_cast<std::chrono::microseconds>(splayInsertEnd - splayInsertStart);
            // print timer
            std::cout << "Splay Tree insert time: " << splayInsertTime.count() << " microseconds" << std::endl;
            // RB insertions
            auto RBInsertStart = std::chrono::steady_clock::now();
            for (const Node& val : data){
                if (val.year == year){ // if the year is our target
                    RB.insert(RB.root, val.country, val.data);
                }
            }
            auto RBInsertEnd = std::chrono::steady_clock::now();
            auto RBInsertDuration = std::chrono::duration_cast<std::chrono::microseconds>(RBInsertEnd - RBInsertStart);
            // print timer
            std::cout << "Red Black tree insert time: " << RBInsertDuration.count() << " microseconds" << std::endl;
        }
        else if (userInput == "3") {
            // splay searches
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore userInput
            std::cout << "Enter the country of interest: " << std::endl;
            std::string country;
            std::getline(std::cin, country);
            auto splaySearchStart = std::chrono::steady_clock::now();
            splay.search(country);
            auto splaySearchEnd = std::chrono::steady_clock::now();
            auto splaySearchTime = std::chrono::duration_cast<std::chrono::microseconds>(splaySearchEnd - splaySearchStart);
            // print timer
            std::cout << "Splay tree search time: " << splaySearchTime.count() << " microseconds" << std::endl;
            // RB searches
            auto RBSearchStart = std::chrono::steady_clock::now();
            RB.search(RB.root, country);
            auto RBSearchEnd = std::chrono::steady_clock::now();
            auto RBSearchTime = std::chrono::duration_cast<std::chrono::microseconds>(RBSearchEnd - RBSearchStart);
            // print timer
            std::cout << "Red Black tree search time: " << RBSearchTime.count() << " microseconds" << std::endl;
            //RB.levelOrder(RB.root);
        }
        else if (userInput == "4") {
            std::string data;
            std::cout << "Enter the data point of interest: " << std::endl;
            std::cin >> data;
            // splay search data
            auto splayStartTime = std::chrono::steady_clock::now();
            splay.searchData(data);
            auto splayEndTime = std::chrono::steady_clock::now();
            auto splayDuration = std::chrono::duration_cast<std::chrono::microseconds>(splayEndTime - splayStartTime);
            // print timer
            std::cout << "Splay Tree search time: " << splayDuration.count() << " microseconds" << std::endl;
            // RB search data
            auto RBStartTime = std::chrono::steady_clock::now();
            RB.searchData(RB.root, data);
            auto RBEndTime = std::chrono::steady_clock::now();
            auto RBDuration = std::chrono::duration_cast<std::chrono::microseconds>(RBEndTime - RBStartTime);
            // print timer
            std::cout << "Red Black tree search time: " << RBDuration.count() << " microseconds" << std::endl;
        }
        else if (userInput == "5") {
            splay.deleteTree();
            RB.deleteTree();
        }
        else {
            std::cout << "Invalid option. Please enter a new digit from 1-6, inclusive." << std::endl;
        }
        std::cout << std::endl;
        printMenu();
        std::cin >> userInput;
    }
    csv.clear();
    // deallocate memory
    splay.deleteTree();
    RB.deleteTree();
    return 0;
}
