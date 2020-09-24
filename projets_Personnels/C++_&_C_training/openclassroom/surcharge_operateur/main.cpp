#include <iostream>
#include "Duree.h"

int main()
{
    Duree duree1(0, 10, 28), duree2(0, 15, 2);

    if(duree1 == duree2)
    {
     std::cout << "Les deux durees sont egales !" << std::endl;
    }
    return 0;
}
