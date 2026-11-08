#include <iostream>
#include <string>
#include <charconv>

int main() {
    std::string start_pop = "";
    int i_start_pop = 0;
    
    std::string births = "";
    int i_births = 0;
    
    std::string deaths = "";
    int i_deaths = 0;
    
    std::cout << "Starting population? "; std::getline(std::cin, start_pop);
    std::cout << "How many births? "; std::getline(std::cin ,births);
    std::cout << "How many deaths? "; std::getline(std::cin, deaths);
    
    auto start_result = 
        std::from_chars(
        start_pop.data(), 
        start_pop.data() + start_pop.size(), 
        i_start_pop);
 
    auto births_result = 
        std::from_chars(
        births.data(), 
        births.data() + births.size(), 
        i_births);
    
    auto deaths_result = 
        std::from_chars(
        deaths.data(), 
        deaths.data() + deaths.size(), 
        i_deaths);
    std::cout << std::endl;
    
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
    
    
    
}
