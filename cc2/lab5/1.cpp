#include <iostream>

template <typename T>
void ordenarAsc(T v[], int size) {
  T aux;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1 - i; j++) {
      if (v[j] > v[j + 1]) {
        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
      }
    }
  }
}

template <typename T>
void ordenarDesc(T v[], int size) {
  T aux;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1 - i; j++) {
      if (v[j] < v[j + 1]) {
        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
      }
    }
  }
}

template <typename T>
void print(T v[], int size) {
  for (int i = 0; i < size; i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int arr[] = {9, 2, 6, 8, 20};
  int size = sizeof(arr) / sizeof(arr[0]);
  
  std::cout << "original: ";
  print(arr, size);
  
  ordenarAsc(arr, size);
  std::cout << "ascendente: ";
  print(arr, size);
  
  ordenarDesc(arr, size);
  std::cout << "descendente: ";
  print(arr, size);
}

