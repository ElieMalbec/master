#include <iostream>
#include <string>
#include <vector>

int main(){
  std::vector<std::string> vec;
  std::string x;
  std::cout << "pick your strings. CTRL Z on windows or CTRL D on unix to quit" << std::endl;
  while (std::cin >> x){
    vec.push_back(x);
  }
  if (vec.size() == 0) {
    std::cout << "no strings written" << std::endl;
    return 1;
  }
  else if (vec.size() == 1){
    std::cout << "your first element is the biggest element" << std::endl;
    return 0;
  }
  else {
    int max = 0;
    int pos = 0;
    for (int i(0); i < vec.size(); i++){
      if (vec[i].size() > max){
        max = vec[i].size();
        pos = i;
      }
    }
    std::cout << "Your longest string is : " << vec[pos] << " with " << max << " caracters" << std::endl;
  }
  return 0;
}
