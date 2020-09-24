#include <iostream>

int main(){
  int nb1,nb2;
  std::cout << "Give two numbers" << std::endl;
  std::cin >> nb1;
  std::cin >> nb2;
  if (nb1 >= nb2){
    std::cout << "Number 1 is bigger !" << std::endl;
  }
  else {
    std::cout << "Number 2 is bigger !" << std::endl;
  }
  return 0;
}
