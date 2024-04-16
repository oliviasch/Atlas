#pragma once
struct Node{
    // Data forming the tree
    std::string country;
    double data;

    // All data collected about a country
    int year;
    double co2;
    double co2GrowthAbs;
    double co2GrowthPrct;
    double coalCo2;

    // Tree-specific attributes
    Node* left;
    Node* right;
    // constructor initializer, data to equal whatever is of interest or smth
    Node(std::string country, double data) : country(std::move(country)), data(data), left(nullptr), right(nullptr){}
};