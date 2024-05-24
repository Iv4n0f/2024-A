#include <iostream>
#include <string>
using namespace std;

double stringToDouble(const string &str) {
  double result = 0.0;
  int decimalPosition = -1;
  bool isDecimal = false;
  int digitsAfterDecimal = 0;
  bool isNegative = false;
  int start = 0;

  // Check for negative sign at the beginning
  if (str[0] == '-') {
    isNegative = true;
    start = 1;
  }

  for (int i = start; i < str.length(); i++) {
    char c = str[i];
    if (c >= '0' && c <= '9') {
      if (isDecimal) {
        digitsAfterDecimal++;
        result = result * 10 + (c - '0');
      } else {
        result = result * 10 + (c - '0');
      }
    } else if (c == '.' && !isDecimal) {
      isDecimal = true;
      decimalPosition = digitsAfterDecimal;
    } else {
      throw invalid_argument("Cadena no válida para conversión a double");
    }
  }

  if (isDecimal) {
    double divisor = 1;
    for (int i = 0; i < digitsAfterDecimal; i++) {
      divisor *= 10;
    }
    result /= divisor;
  }

  if (isNegative) {
    result = -result;
  }

  return result;
}
int main(){
  string op;

  double n = 1.0;
  
  getline(cin,op);

  double n2 = stringToDouble(op);
  cout<<n +n2;
};
