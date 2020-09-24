#include <iostream>

using namespace std;
int main(){
  cout << "Choose your two numbers and operand"<<endl;
  while (true){
    int number1,number2,result;
    string operand;

    cout << "Choose your first number"<<endl;
    cin >> number1;

    hi:
    cout << "Choose your operand (+,-,/,*,%)" << endl;
    cin >> operand;
    cin.ignore();
    if ((operand == "+") || (operand == "%") || (operand == "-") || (operand == "/") || (operand == "*")){
      goto hey;
    }
    else{
      goto hi;
    }
    hey :
    cout << "Choose your second number"<<endl;
    cin >> number2;

    if (operand=="+"){
      result = number1+number2;
    }
    else if (operand=="-"){
      result = number1-number2;
    }
    else if (operand=="*"){
      result = number1*number2;
    }
    else if (operand=="/"){
      result = number1/number2;
    }
    else if (operand=="%"){
      result = number1%number2;
    }
    cout << "This is your result : " << result << endl;
  }

  return 0;
}
