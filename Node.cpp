#include "Node.h"
std::vector<Node> Node::readFile(const std::vector<std::vector<std::string>>& csv, const std::string& attribute){
    std::vector<Node> data;
    // attribute map - user input / node's corresponding data
    std::unordered_map<std::string, std::string Node::*> attributes = {
            {"country", &Node::country},
            {"year", &Node::year},
            {"iso", &Node::iso},
            {"population", &Node::population},
            {"gdp", &Node::gdp},
            {"cement_co2", &Node::cement_co2},
            {"cement_co2_capita", &Node::cement_co2_capita},
            {"co2", &Node::co2},
            {"co2_growth_abs", &Node::co2_growth_abs},
            {"co2_growth_prct", &Node::co2_growth_prct},
            {"co2_incl_luc", &Node::co2_incl_luc},
            {"co2_incl_luc_growth_abs", &Node::co2_incl_luc_growth_abs},
            {"co2_incl_luc_growth_pcrt", &Node::co2_incl_luc_growth_pcrt},
            {"co2_incl_luc_per_capita", &Node::co2_incl_luc_per_capita},
            {"co2_incl_luc_per_gdp", &Node::co2_incl_luc_per_gdp},
            {"co2_incl_luc_per_unit_energy", &Node::co2_incl_luc_per_unit_energy},
            {"co2_per_capita", &Node::co2_per_capita},
            {"co2_per_gdp", &Node::co2_per_gdp},
            {"co2_per_unit_energy", &Node::co2_per_unit_energy},
            {"coal_co2", &Node::coal_co2},
            {"coal_co2_per_capita", &Node::coal_co2_per_capita},
            {"consumption_co2", &Node::consumption_co2},
            {"consumption_co2_per_capita", &Node::consumption_co2_per_capita},
            {"consumption_co2_per_gdp", &Node::consumption_co2_per_gdp},
            {"cum_cement_co2", &Node::cum_cement_co2},
            {"cum_co2", &Node::cum_co2},
            {"cum_co2_incl_luc", &Node::cum_co2_incl_luc},
            {"cum_coal_co2", &Node::cum_coal_co2},
            {"cum_flaring_co2", &Node::cum_flaring_co2},
            {"cum_gas_co2", &Node::cum_gas_co2},
            {"cum_luc_co2", &Node::cum_luc_co2},
            {"cum_oil_co2", &Node::cum_oil_co2},
            {"cum_other_co2", &Node::cum_other_co2},
            {"energy_per_capita", &Node::energy_per_capita},
            {"energy_per_gdp", &Node::energy_per_gdp},
            {"flaring_co2", &Node::flaring_co2},
            {"flaring_co2_per_capita", &Node::flaring_co2_per_capita},
            {"gas_co2", &Node::gas_co2},
            {"gas_co2_per_capita", &Node::gas_co2_per_capita},
            {"ghg_ecl_lucf_per_capita", &Node::ghg_ecl_lucf_per_capita},
            {"ghg_per_capita", &Node::ghg_per_capita},
            {"land_use_change_co2", &Node::land_use_change_co2},
            {"land_use_change_co2_per_capita", &Node::land_use_change_co2_per_capita},
            {"methane", &Node::methane},
            {"methane_per_capita", &Node::methane_per_capita},
            {"nitrous_oxide", &Node::nitrous_oxide},
            {"nitrous_oxide_per_capita", &Node::nitrous_oxide_per_capita},
            {"oil_co2", &Node::oil_co2},
            {"oil_co2_per_capita", &Node::oil_co2_per_capita},
            {"other_co2_per_capita", &Node::other_co2_per_capita},
            {"other_industry_co2", &Node::other_industry_co2},
            {"primary_energy_consumption", &Node::primary_energy_consumption},
            {"share_global_cement_co2", &Node::share_global_cement_co2},
            {"share_global_co2", &Node::share_global_co2},
            {"share_global_co2_incl_luc", &Node::share_global_co2},
            {"share_global_coal_co2", &Node::share_global_coal_co2},
            {"share_global_cum_cement_co2", &Node::share_global_cum_cement_co2},
            {"share_global_cum_co2", &Node::share_global_cum_co2},
            {"share_global_cum_co2_incl_luc", &Node::share_global_cum_co2_incl_luc},
            {"share_global_cum_coal_co2", &Node::share_global_cum_coal_co2},
            {"share_global_cum_flaring_co2", &Node::share_global_cum_flaring_co2},
            {"share_global_cum_gas_co2", &Node::share_global_cum_gas_co2},
            {"share_global_cum_luc_co2", &Node::share_global_cum_luc_co2},
            {"share_global_cum_oil_co2", &Node::share_global_cum_oil_co2},
            {"share_global_cum_other_co2", &Node::share_global_cum_other_co2},
            {"share_global_flaring_co2", &Node::share_global_flaring_co2},
            {"share_global_gas_co2", &Node::share_global_gas_co2},
            {"share_global_luc_co2", &Node::share_global_luc_co2},
            {"share_global_oil_co2", &Node::share_global_oil_co2},
            {"share_global_other_co2", &Node::share_global_other_co2},
            {"share_of_temperature_change_from_ghg", &Node::share_of_temperature_change_from_ghg},
            {"temperature_change_from_ch4", &Node::temperature_change_from_ch4},
            {"temperature_change_from_co2", &Node::temperature_change_from_co2},
            {"temperature_change_from_ghg", &Node::temperature_change_from_ghg},
            {"temperature_change_from_n2o", &Node::temperature_change_from_n2o},
            {"total_ghg", &Node::total_ghg},
            {"total_ghg_excl_lucf", &Node::total_ghg_excl_lucf},
            {"trade_co2", &Node::trade_co2},
            {"trade_co2_share", &Node::trade_co2_share}
    };
    // move data into vector of data objects
    for (const auto& row : csv) {
        // create data object
        Node dataObj(row[0], "0"); // temporary data value
        dataObj.country = row[0];
        dataObj.year = row[1];
        dataObj.iso = row[2];
        dataObj.population = row[3];
        dataObj.gdp = row[4];
        dataObj.cement_co2 = row[5];
        dataObj.cement_co2_capita = row[6];
        dataObj.co2 = row[7];
        dataObj.co2_growth_abs = row[8];
        dataObj.co2_growth_prct = row[9];
        dataObj.co2_incl_luc = row[10];
        dataObj.co2_incl_luc_growth_abs = row[11];
        dataObj.co2_incl_luc_growth_pcrt = row[12];
        dataObj.co2_incl_luc_per_capita = row[13];
        dataObj.co2_incl_luc_per_gdp = row[14];
        dataObj.co2_incl_luc_per_unit_energy = row[15];
        dataObj.co2_per_capita = row[16];
        dataObj.co2_per_gdp = row[17];
        dataObj.co2_per_unit_energy = row[18];
        dataObj.coal_co2 = row[19];
        dataObj.coal_co2_per_capita = row[20];
        dataObj.consumption_co2 = row[21];
        dataObj.consumption_co2_per_capita = row[22];
        dataObj.consumption_co2_per_gdp = row[23];
        dataObj.cum_cement_co2 = row[24];
        dataObj.cum_co2 = row[25];
        dataObj.cum_co2_incl_luc = row[26];
        dataObj.cum_coal_co2 = row[27];
        dataObj.cum_flaring_co2 = row[28];
        dataObj.cum_gas_co2 = row[29];
        dataObj.cum_luc_co2 = row[30];
        dataObj.cum_oil_co2 = row[31];
        dataObj.cum_other_co2 = row[32];
        dataObj.energy_per_capita = row[33];
        dataObj.energy_per_gdp = row[34];
        dataObj.flaring_co2 = row[35];
        dataObj.flaring_co2_per_capita = row[36];
        dataObj.gas_co2 = row[37];
        dataObj.gas_co2_per_capita = row[38];
        dataObj.ghg_ecl_lucf_per_capita = row[39];
        dataObj.ghg_per_capita = row[40];
        dataObj.land_use_change_co2 = row[41];
        dataObj.land_use_change_co2_per_capita = row[42];
        dataObj.methane = row[43];
        dataObj.methane_per_capita = row[44];
        dataObj.nitrous_oxide = row[45];
        dataObj.nitrous_oxide_per_capita = row[46];
        dataObj.oil_co2 = row[47];
        dataObj.oil_co2_per_capita = row[48];
        dataObj.other_co2_per_capita = row[49];
        dataObj.other_industry_co2 = row[50];
        dataObj.primary_energy_consumption = row[51];
        dataObj.share_global_cement_co2 = row[52];
        dataObj.share_global_co2 = row[53];
        dataObj.share_global_co2_incl_luc = row[54];
        dataObj.share_global_coal_co2 = row[55];
        dataObj.share_global_cum_cement_co2 = row[56];
        dataObj.share_global_cum_co2 = row[57];
        dataObj.share_global_cum_co2_incl_luc = row[58];
        dataObj.share_global_cum_coal_co2 = row[59];
        dataObj.share_global_cum_flaring_co2 = row[60];
        dataObj.share_global_cum_gas_co2 = row[61];
        dataObj.share_global_cum_luc_co2 = row[62];
        dataObj.share_global_cum_oil_co2 = row[63];
        dataObj.share_global_cum_other_co2 = row[64];
        dataObj.share_global_flaring_co2 = row[65];
        dataObj.share_global_gas_co2 = row[66];
        dataObj.share_global_luc_co2 = row[67];
        dataObj.share_global_oil_co2 = row[68];
        dataObj.share_global_other_co2 = row[69];
        dataObj.share_of_temperature_change_from_ghg = row[70];
        dataObj.temperature_change_from_ch4 = row[71];
        dataObj.temperature_change_from_co2 = row[72];
        dataObj.temperature_change_from_ghg = row[73];
        dataObj.temperature_change_from_n2o = row[74];
        dataObj.total_ghg = row[75];
        dataObj.total_ghg_excl_lucf = row[76];
        dataObj.trade_co2 = row[77];
        // what():  std::bad_alloc instance if this is not commented? not sure why
        //dataObj.trade_co2_share = row[78];
        // initializes data of interest to user specification
        auto it = attributes.find(attribute);
        if (it != attributes.end()){ dataObj.data = dataObj.*(it->second); }
        data.push_back(dataObj);
    }
    return data;
}