#include <iostream>
#include <vector>

int plus(const int a, const int b){
    return a + b;
}

double plus(const double a, const double b){
    return a + b;
}

int somme(const std::vector<int> &v){
    int sum = 0;
    for (int i: v){
        sum += i;
    }
    return sum;
}

double somme(const std::vector<double> &v){
    double sum = 0;
    for (double i: v){
        sum += i;
    }
    return sum;
}

int main(void){
    int a = 5, b = 5;
    short c = 3;
    float d = 6, e = 6;
    double f = 25, g = 25;

    std::cout << plus(a,b) << "\n";
    std::cout << plus(a,c) << "\n";
    std::cout << plus(d,e) << "\n";
    std::cout << plus(f, g) << "\n";
    // std::cout << plus(a, g) << "\n";
    // La derniere ne fonctionne pas, ambiguité
    std::vector<int> v = {1,2,3};
    std::vector<double> x = {5,6,7};
    std::vector<short> y = {10,11,12};

    std::cout << somme(v) << "\n";
    std::cout << somme(x) << "\n";
    // std::cout << somme(y);
    // Pas de surcharge pour les short
}