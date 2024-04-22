#include <iostream>

using namespace std;

int *fun(int *&p, int n) {
  p = new int[n];
  return p;
}

int main() {
  int *p;
  fun(p, 5);
  for (int i = 0; i < 5; i++) {
    cout << p[i] << " ";
  }
}
