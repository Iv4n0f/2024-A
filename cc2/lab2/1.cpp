#include <iostream>

using namespace std;

int main() {
  int v;
  cout << "Ingresar numero: " << endl;
  cin >> v;

  int *ptr = &v;
  cout << "Direccion: " << ptr;
}
