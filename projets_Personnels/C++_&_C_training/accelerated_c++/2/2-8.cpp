#include <iostream>

int main(){
  int result = 1;
  for(int i=1; i < 11; i++){
    result*= i;
    std::cout << result << std::endl;
  }
  return 0;
}
