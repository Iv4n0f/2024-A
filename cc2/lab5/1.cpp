#include <iostream>

template <typename T>
T ordenar(char c, T v[]){

  T aux;
  size_t
  for (T i = 0; i < size(); i++) {
    for (T j = 0; j < size() - 1 - i; j++) {
      if (v[j] > v[j + 1]) {
        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
      }
    }
  }
  return v;
}

}
