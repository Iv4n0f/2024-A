#include <iostream>

constexpr bool isPrime(int n) {
  if (n <= 1)
    return false;

  for (int i = n - 1; i >= 2; i--) {
    if (n % i == 0 )
      return false;
  }

  return true;
}

int main() {

  constexpr bool _10 = isPrime(10);
  constexpr bool _11 = isPrime(11);
  constexpr bool _12 = isPrime(12);

  std::cout<<"10: "<<_10<<std::endl;
  std::cout<<"11: "<<_11<<std::endl;
  std::cout<<"12: "<<_12<<std::endl;
}
