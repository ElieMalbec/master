#include <iostream>
#include <vector>

int main()
{
    std::vector<int> collection { 1, -8, 4, 654, -7785, 0, 42 };
    // On passe l'itérateur de début et celui de fin.
    std::vector<int> sous_ensemble { std::begin(collection) + 1, std::begin(collection) + 5 };

    // On affiche pour vérifier.
    for (auto element : sous_ensemble)
    {
        std::cout << element << std::endl;
    }

    return 0;
}
