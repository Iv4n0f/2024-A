#include <iostream>

class DynamicArray {
  int size;
  int *data;

public:
  int getSize() const { return size; }

  int get(int index) { return data[index]; }

  DynamicArray() {
    size = 0;
    data = new int[1];
  }

  DynamicArray(int arr[], int size) {
    this->size = size;
    data = new int[size];

    for (int i = 0; i < size; i++) {
      data[i] = arr[i];
    }
  }

  DynamicArray(DynamicArray &o) {
    size = o.getSize();
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = o.get(i);
    }
  }

  ~DynamicArray() { delete[] data; }

  void push_back(int val) {
    int *temp = new int[size + 1];
    for (int i = 0; i < size; i++) {
      temp[i] = data[i];
    }
    temp[size] = val;
    size++;
    data = temp;
  }

  void insert(int val, int index) {
    int *temp = new int[size + 1];
    for (int i = 0; i < index; i++) {
      temp[i] = data[i];
    }
    temp[index] = val;
    for (int i = index+1; i< size +1;i++){
      temp[i] = data[i-1];
    }
    size++;
    data = temp;
  }

  void remove(int index) {
    int *temp = new int[size-1];
    for (int i = 0; i < index;i++){
      temp[i] = data[i];
    }
    for (int i = index+1; i < size; i++){
      temp[i-1] = data[i];
    }
    size--;
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
  DynamicArray da(arr, 3);
  da.push_back(7);
  da.print();
  da.insert(9,1);
  da.print();
  da.remove(3);
  da.print();
}
