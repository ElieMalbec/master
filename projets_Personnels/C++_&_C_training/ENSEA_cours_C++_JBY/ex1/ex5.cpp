#include <iostream>

void    inputNumber(int &nb){
    std::cout << "pick number\n";
    std::cin >> nb;
}

void    isEven(const int &nb){
    if (nb%2 == 0) {
        std::cout << "pair\n";
    }
    else {
        std::cout << "impair\n";
    }
}

int main(){
    int n;
    inputNumber(n);
    isEven(n);
    return 0;
}