#include <iostream>

int    facto(int nb){
    if (nb == 0){
        return 0;
    }
    if (nb == 1){
        return 1;
    }
    else {
        return facto(nb - 1) * nb;
    }
}

int main(){
    int x;
    std::cout << "choisir nb pour factorielle iterative: ";
    std::cin >> x;

    int sum = 1;
    for (int i = 1; i <= x; i++){
        sum *= i;
    }
    std::cout << "the factorielle ite is : " << sum << "\n";

    std::cout << "the factorielle recu is : " << facto(x) << "\n";

    return 0;
}