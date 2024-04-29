#include <iostream>

template<typename T>
class GenericStaticArray {
  int size;
  T *data;

public:
  int getSize() const { return size; }
  T get(int i) const { return data[i]; }
  void set(T val, int i) { data[i] = val; }

  GenericStaticArray(T a[], int size) {
    data = new T[size];
    this->size = size;
    for (int i = 0; i < size; i++) {
      data[i] = a[i];
    }
  }

  GenericStaticArray(const GenericStaticArray &o) {
    size = o.getSize();
    data = new T[size];
    for (int i = 0; i < size; i++) {
      data[i] = o.get(i);
    }
  }

  ~GenericStaticArray() { delete[] data; }

  void print() {
    for (int i = 0; i < size; i++) {
      std::cout << data[i] << " - ";
    }
    std::cout << std::endl;
  }
};

int main() {
  int arr[] = {1, 2, 3};
  GenericStaticArray<int> sa(arr, 3); // Usando int como tipo de dato
  sa.print();
  sa.set(8, 1);
  sa.print();
}
