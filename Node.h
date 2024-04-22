#pragma once
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
struct Node{
    // constructor initializer
    Node(std::string country, std::string data) : country(std::move(country)), data(std::move(data)), left(nullptr), right(nullptr), parent(nullptr){}
    Node(std::string country, std::string data, bool color) : country(std::move(country)), data(std::move(data)), color(color), left(nullptr), right(nullptr), parent(nullptr){}
    // tree-specific attributes
    Node* left;
    Node* right;
    Node* parent;
    bool color;
    // data forming the tree
    std::string country;
    std::string data;
    // other csv attributes
    std::string year;
    std::string iso;
    std::string population;
    std::string gdp;
    std::string cement_co2;
    std::string cement_co2_capita;
    std::string co2;
    std::string co2_growth_abs;
    std::string co2_growth_prct;
    std::string co2_incl_luc;
    std::string co2_incl_luc_growth_abs;
    std::string co2_incl_luc_growth_pcrt;
    std::string co2_incl_luc_per_capita;
    std::string co2_incl_luc_per_gdp;
    std::string co2_incl_luc_per_unit_energy;
    std::string co2_per_capita;
    std::string co2_per_gdp;
    std::string co2_per_unit_energy;
    std::string coal_co2;
    std::string coal_co2_per_capita;
    std::string consumption_co2;
    std::string consumption_co2_per_capita;
    std::string consumption_co2_per_gdp;
    std::string cum_cement_co2;
    std::string cum_co2;
    std::string cum_co2_incl_luc;
    std::string cum_coal_co2;
    std::string cum_flaring_co2;
    std::string cum_gas_co2;
    std::string cum_luc_co2;
    std::string cum_oil_co2;
    std::string cum_other_co2;
    std::string energy_per_capita;
    std::string energy_per_gdp;
    std::string flaring_co2;
    std::string flaring_co2_per_capita;
    std::string gas_co2;
    std::string gas_co2_per_capita;
    std::string ghg_ecl_lucf_per_capita;
    std::string ghg_per_capita;
    std::string land_use_change_co2;
    std::string land_use_change_co2_per_capita;
    std::string methane;
    std::string methane_per_capita;
    std::string nitrous_oxide;
    std::string nitrous_oxide_per_capita;
    std::string oil_co2;
    std::string oil_co2_per_capita;
    std::string other_co2_per_capita;
    std::string other_industry_co2;
    std::string primary_energy_consumption;
    std::string share_global_cement_co2;
    std::string share_global_co2;
    std::string share_global_co2_incl_luc;
    std::string share_global_coal_co2;
    std::string share_global_cum_cement_co2;
    std::string share_global_cum_co2;
    std::string share_global_cum_co2_incl_luc;
    std::string share_global_cum_coal_co2;
    std::string share_global_cum_flaring_co2;
    std::string share_global_cum_gas_co2;
    std::string share_global_cum_luc_co2;
    std::string share_global_cum_oil_co2;
    std::string share_global_cum_other_co2;
    std::string share_global_flaring_co2;
    std::string share_global_gas_co2;
    std::string share_global_luc_co2;
    std::string share_global_oil_co2;
    std::string share_global_other_co2;
    std::string share_of_temperature_change_from_ghg;
    std::string temperature_change_from_ch4;
    std::string temperature_change_from_co2;
    std::string temperature_change_from_ghg;
    std::string temperature_change_from_n2o;
    std::string total_ghg;
    std::string total_ghg_excl_lucf;
    std::string trade_co2;
    // read csv file
    static std::vector<Node> readFile(const std::vector<std::vector<std::string>>& csv, const std::string& attribute);
};
