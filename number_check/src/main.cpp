#include <iostream>

int main() {
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
        return 1;
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
