#include <iostream>

template <typename T>
class GenericDynamicArray {
  int size;
  T *data;

public:
  int getSize() const { return size; }

  T get(int index) const { return data[index]; }

  GenericDynamicArray() : size(0), data(nullptr) {}

  GenericDynamicArray(T arr[], int size) : size(size) {
    data = new T[size];
    for (int i = 0; i < size; ++i) {
      data[i] = arr[i];
    }
  }

  GenericDynamicArray(const GenericDynamicArray &o) : size(o.size) {
    data = new T[size];
    for (int i = 0; i < size; ++i) {
      data[i] = o.data[i];
    }
  }

  ~GenericDynamicArray() { delete[] data; }

  void push_back(const T &val) {
    T *temp = new T[size + 1];
    for (int i = 0; i < size; ++i) {
      temp[i] = data[i];
    }
    temp[size] = val;
    ++size;
    delete[] data;
    data = temp;
  }

  void insert(const T &val, int index) {
    T *temp = new T[size + 1];
    for (int i = 0; i < index; ++i) {
      temp[i] = data[i];
    }
    temp[index] = val;
    for (int i = index + 1; i < size + 1; ++i) {
      temp[i] = data[i - 1];
    }
    ++size;
    delete[] data;
    data = temp;
  }

  void remove(int index) {
    T *temp = new T[size - 1];
    for (int i = 0; i < index; ++i) {
      temp[i] = data[i];
    }
    for (int i = index + 1; i < size; ++i) {
      temp[i - 1] = data[i];
    }
    --size;
    delete[] data;
    data = temp;
  }

  void print() const {
    for (int i = 0; i < size; ++i) {
      std::cout << data[i] << " - ";
    }
    std::cout << std::endl;
  }
};

int main() {
  GenericDynamicArray<int> da{};
  da.push_back(7);
  da.push_back(9);
  da.push_back(10);
  da.push_back(3);
  da.insert(22,2);

  da.print();

  return 0;
}
