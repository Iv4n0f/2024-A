#include <iostream>
char *mem() {
  char cad[] = "prueba";
  return cad;
}

int main() {
  char *ptr = mem();
  std::cout<< "antes de liberar memoria: " << ptr << std::endl;

  delete[] ptr;

  std::cout << "después de liberar memoria: " << ptr << std::endl;
  return 0;
}
