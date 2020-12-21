#include <iostream>
#include <vector>

void    remplir(std::vector<int> &v, int size){
    for (int i = 0; i < size; i++){
        std::cout << "remplir votre tableau :";
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
        std::cout << "\n";
    }
}

void    isCroissante(std::vector<int> &v, int size) {
    for (int i = 0; i < size - 1; i++){
        if (v[i] < v[i + 1]){
            continue;
        }
        else {
            std::cout << "Pas croissante" << "\n";
            return;
        }
    }
    std::cout << "Est croissante" << "\n";
}

void    isDecroissante(std::vector<int> &v, int size) {
    for (int i = 0; i < size - 1; i++){
        if (v[i] > v[i + 1]){
            continue;
        }
        else {
            std::cout << "Pas décroissante" << "\n";
            return;
        }
    }
    std::cout << "Est décroissante" << "\n";
}

void    isConstant(std::vector<int> &v, int size) {
    for (int i = 0; i < size - 1; i++){
        if (v[i] == v[i + 1]){
            continue;
        }
        else {
            std::cout << "Pas constant" << "\n";
            return;
        }
    }
    std::cout << "Est constant" << "\n";
}

int main(){
    std::vector<int> v;
    std::cout << "size of the array : ";
    int n;
    std::cin >> n;
    remplir(v,n);

    for (auto i : v){
        std::cout << i << " ";
    }
    std::cout << "\n";
    isCroissante(v, n);
    isDecroissante(v, n);
    isConstant(v,n);
    return 0;
}