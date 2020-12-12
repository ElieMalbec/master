#include <iostream>

int main(void){
    std::cout << "Enter a number :";
    int x;
    std::cin >> x;
    std::cout << "Double that number is :" << (x*2) << "\n";
    std::cout << "Triple that number is :" << (x*3) << "\n";    
    return 0;
}