#include <iostream>
#include <string>
#include <charconv>
#include <optional>
#include <cstdlib>

int update_pop(int starting, int migrants, int births, int deaths)
{
    int population = starting + migrants + births - deaths;
    if (population <= 0)
    {
        std::cout << "The area is currently devoid of life." << std::endl;
        population = 0;
        return population;
    }
    else
    {
        std::cout << "The population of this area is: " << population << std::endl;
        return population;
    }
}

void require_valid_input(bool value)
{
    if (!value)
    {
        std::cout << "Maximum attempts reached. \n";
        std::exit(1);
    }
}

std::optional<int> get_population_input(const std::string& question)
{
    std::string population = "";
    int i_population = 0;
    int attempts = 0;
    
    while (attempts < 3)
    {
        std::cout << question; std::getline(std::cin, population);
        
        auto start_result = 
           std::from_chars(
           population.data(), 
           population.data() + population.size(), 
           i_population);
            
        if (!(start_result.ec == std::errc{}) || 
            !(start_result.ptr == population.data() + population.size()))
        {
            std::cout << "Make sure input uses standard numbers only." << std::endl;
            attempts++;
        }
        else if (i_population < 0)
        {
            std::cout << "Input cannot be negative." << std::endl;
            attempts++;
        }
        else
        {
            return i_population;
        }
    }
    return std::nullopt;
}

int main() 
{
    std::optional<int> starting = get_population_input("What is the starting population for this settlement?");
    require_valid_input(starting.has_value());   
    std::optional<int> migrants = get_population_input("How many migrants to this settlement in the next year?");
    require_valid_input(migrants.has_value());
    std::optional<int> births = get_population_input("How many births in this settlement in the next year?");
    require_valid_input(births.has_value());
    std::optional<int> deaths = get_population_input("How many deaths in this settlement in the next year?");
    require_valid_input(deaths.has_value());    
        
    int one_year_pop = update_pop(
        starting.value(), 
        migrants.value(), 
        births.value(), 
        deaths.value());    
}
