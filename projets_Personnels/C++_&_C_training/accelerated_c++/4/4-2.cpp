#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;

int main(){
  for (int i(0); i < 10001; i++){
    cout << std::setw(2) << i << " : " ;
    cout << std::setw(3) << sqrt(i) << endl;
  }

  return 0;
}
