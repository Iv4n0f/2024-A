#include <iostream>

using namespace std;

int main() {
  int *p1 = new int;
  int *p2 = new int;

  cout << "N1 = ";
  cin >> *p1;

  cout << "N2 = ";
  cin >> *p2;

  cout<<"Multiplicacion = "<< *p1 * *p2;
}
