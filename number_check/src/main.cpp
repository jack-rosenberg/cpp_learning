#include <iostream>
#include <string>

int main() {
    
    std::string allowed_char = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
   
    std::string char_name = "";
    std::cout << "Enter your name: ";
    std::getline(std::cin,char_name);
    
    for (char letters : char_name)
        {
        if (allowed_char.find(letters) == std::string::npos)
            {
            std::cout << "Your name uses symbols or numbers \n";
            return 3;
            }
        }
    
    if (char_name.empty())
        {
        std::cout << "Your name needs characters \n";
        return 4;
        }
        
    std::cout << "Welcome, " << char_name << std::endl;
    
    int start_number = 0;
    std::cout << "Enter your starting number: ";
    
    if (!(std::cin >> start_number))
        {
        std::cout << "Please enter a number.";
        return 1;
        }
    
    int comp_number = 0;
    std::cout << "Enter your comparison number: ";
    
    if (!(std::cin >> comp_number))
        {
        std::cout << "Please enter a number.";
        return 2;
        }
    
    if (start_number == comp_number )
        {
        std::cout << "Equal to " << start_number;
        }
        else if (comp_number < start_number)
            {
            std::cout << "Less than " << start_number;
            }
        else
            {
            std::cout << "Greater than " << start_number;
            }
    return 0;
}
