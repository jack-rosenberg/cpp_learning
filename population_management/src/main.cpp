#include <iostream>
#include <string>
#include <charconv>

int main() {
    std::string start_pop = "";
    int i_start_pop = 0;
    
    std::string migrant_pop = "";
    int i_migrant_pop = 0;
    
    std::string births = "";
    int i_births = 0;
    
    std::string deaths = "";
    int i_deaths = 0;
    
    std::cout << "Starting population? "; std::getline(std::cin, start_pop);
    
    auto start_result = 
       std::from_chars(
       start_pop.data(), 
       start_pop.data() + start_pop.size(), 
       i_start_pop);
    
    if (!(start_result.ec == std::errc{}) || 
        !(start_result.ptr == start_pop.data() + start_pop.size()))
        {
        std::cout << "Make sure starting population uses standard numbers only." << std::endl;
        return 1;
        }
    
    if (i_start_pop < 0)
        {
        std::cout << "Starting population cannot be negative." << std::endl;
        return 2;
        }
    
    std::cout << "Migrated population in the coming year? "; std::getline(std::cin, migrant_pop);
    
    auto migrant_result = 
       std::from_chars(
       migrant_pop.data(), 
       migrant_pop.data() + migrant_pop.size(), 
       i_migrant_pop);
    
    if (!(migrant_result.ec == std::errc{}) || 
        !(migrant_result.ptr == migrant_pop.data() + migrant_pop.size()))
    {
        std::cout << "Make sure migrant population uses standard numbers only." << std::endl;
        return 3;
    }
    
    if (i_migrant_pop < 0)
    {
        std::cout << "Migrated population cannot be negative." << std::endl;
        return 4;
    }
    
    std::cout << "How many births in the coming year? "; std::getline(std::cin ,births);
    
    auto births_result = 
        std::from_chars(
        births.data(), 
        births.data() + births.size(), 
        i_births);
    
    if (!(births_result.ec == std::errc{}) || 
        !(births_result.ptr == births.data() + births.size()))
        {
        std::cout << "Make sure births uses standard numbers only." << std::endl;
        return 5;
        }
    
    if (i_births < 0)
        {
        std::cout << "Number of births cannot be negatives" << std::endl;
        return 6;
        }
    
    std::cout << "How many deaths in the coming year? "; std::getline(std::cin, deaths);
    
    auto deaths_result = 
        std::from_chars(
        deaths.data(), 
        deaths.data() + deaths.size(), 
        i_deaths);
    std::cout << std::endl;
    
    if (!(deaths_result.ec == std::errc{}) || 
        !(deaths_result.ptr == deaths.data() + deaths.size()))
        {
        std::cout << "Make sure deaths uses standard numbers only." << std::endl;
        return 7;
        }
    
    if (i_deaths < 0)
        {
        std::cout << "Number of deaths cannot be negatives" << std::endl;
        return 8;
        }
    
    int updated_population = i_start_pop + i_migrant_pop + i_births - i_deaths;
    
    if (updated_population <= 0)
        {
        std::cout << "The area is currently devoid of life." << std::endl;
        updated_population = 0;
        return 0;
        }
    else
        {
        std::cout << "The population of this area is: " << updated_population << std::endl;
        return 0;
        }
    
    // Used to output inputted numbers and show if conversion is successful and
    // if the entire input was consumed
    /*
    std::cout << "Starting population: " << i_start_pop << std::endl;
    
    std::cout << std::boolalpha;
    std::cout << "Conversion successful: " 
              << (start_result.ec == std::errc{}) << "\n"
              << "Entire input consumed: " 
              << (start_result.ptr == start_pop.data() + start_pop.size()) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Number of births: " << i_births << std::endl;
    
    std::cout << std::boolalpha;
    std::cout << "Conversion successful: " 
              << (births_result.ec == std::errc{}) << "\n"
              << "Entire input consumed: " 
              << (births_result.ptr == births.data() + births.size()) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Number of deaths: " << i_deaths << std::endl;
        
    std::cout << std::boolalpha;
    std::cout << "Conversion successful: " 
              << (deaths_result.ec == std::errc{}) << "\n"
              << "Entire input consumed: " 
              << (deaths_result.ptr == deaths.data() + deaths.size()) << std::endl;
    */
    
    
}
