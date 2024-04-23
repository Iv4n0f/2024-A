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
    temp[size + 1] = val;
    size++;
  }

  void print() const{
    for (int i = 0; i<size; i++){
      std::cout << data[i]<<" - ";
    }
    std::cout << std::endl;
  }
};

int main(){
  int arr [] = {1,2,3};
  DynamicArray da (arr,3);

}
