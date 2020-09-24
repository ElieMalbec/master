#include <iostream>
#include <string>
 
int main()
{
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name; // frist std::cin step
    std::cout << " Hello, " << name
                << std::endl << "And what is yours?";
    std::cin >> name;  // second std::cin step
    std::cout << "Hello, " << name
                << "; nice to meet you too!" << std::endl;
    return 0;
 
}
