#include <iostream>

using namespace std;

void del(int *&ptr) { ptr = NULL; }

int main() {
  int *ptr;
  cout <<"Antes de funcion:"<< ptr<<endl;
  del(ptr);
  cout <<"Despues de funcion:"<< ptr;
}
