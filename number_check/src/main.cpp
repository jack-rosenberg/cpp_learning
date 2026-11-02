#include <iostream>

int main() {
    int s_number = 0;
    std::cout << "Enter your starting number: ";
    std::cin >> s_number;
    
    int variable = 0;
    std::cout << "Enter your comparison number: ";
    std::cin >> variable;
    
    if (s_number == variable )
        {
        std::cout << "Equal to " << s_number;
        }
        else if (variable < s_number)
            {
            std::cout << "Less than " << s_number;
            }
        else
            {
            std::cout << "Greater than " << s_number;
            }
    return 0;
}
