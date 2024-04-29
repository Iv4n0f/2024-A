#include <iostream>

template <typename T>
class GenericDynamicArray {
  int size;
  T *data;

public:
  int getSize() const { return size; }

  T get(int index) const { return data[index]; }

  GenericDynamicArray() {
    size = 0;
    data = new T[1];
  }

  GenericDynamicArray(T arr[], int size) {
    this->size = size;
    data = new T[size];

    for (int i = 0; i < size; i++) {
      data[i] = arr[i];
    }
  }

  GenericDynamicArray(const GenericDynamicArray &o) {
    size = o.getSize();
    data = new T[size];
    for (int i = 0; i < size; i++) {
      data[i] = o.get(i);
    }
  }

  ~GenericDynamicArray() { delete[] data; }

  void push_back(const T &val) {
    T *temp = new T[size + 1];
    for (int i = 0; i < size; i++) {
      temp[i] = data[i];
    }
    temp[size] = val;
    size++;
    delete[] data;
    data = temp;
  }

  void insert(const T &val, int index) {
    T *temp = new T[size + 1];
    for (int i = 0; i < index; i++) {
      temp[i] = data[i];
    }
    temp[index] = val;
    for (int i = index + 1; i < size + 1; i++) {
      temp[i] = data[i - 1];
    }
    size++;
    delete[] data;
    data = temp;
  }

  void remove(int index) {
    T *temp = new T[size - 1];
    for (int i = 0; i < index; i++) {
      temp[i] = data[i];
    }
    for (int i = index + 1; i < size; i++) {
      temp[i - 1] = data[i];
    }
    size--;
    delete[] data;
    data = temp;
  }

  void print() const {
    for (int i = 0; i < size; i++) {
      std::cout << data[i] << " - ";
    }
    std::cout << std::endl;
  }
};

int main() {
  int arr[] = {1, 2, 3};
  GenericDynamicArray<int> da(arr, 3);
  da.push_back(7);
  da.print();
  da.insert(9, 1);
  da.print();
  da.remove(3);
  da.print();

  return 0;
}
