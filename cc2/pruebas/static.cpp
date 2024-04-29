#include <iostream>

class StaticArray {
  int size;
  int *data;

public:
  int getSize() const { return size; }
  int get(int i) const { return data[i]; }
  void set(int val, int i) { data[i] = val; }

  StaticArray(int a[], int size) {
    data = new int[size];
    this->size = size;
    for (int i = 0; i < size; i++) {
      data[i] = a[i];
    }
  }

  StaticArray(StaticArray &o) {
    size = o.getSize();
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = o.get(i);
    }
  }

  ~StaticArray() { delete[] data; }

  void print() {
    for (int i = 0; i < size; i++) {
      std::cout << data[i] << " - ";
    }
    std::cout << std::endl;
  }
};

int main() {
  int arr[] = {1, 2, 3};
  StaticArray sa(arr,3);
  sa.print();
  sa.set(8,1);
  sa.print();
}
