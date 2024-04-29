#include <iostream>

void ingresar(char *&buffer, int max) {
  buffer = new char[max];
  std::cout << "Ingresar texto:";
  char *ptr = buffer;
  char in;
  while (true) {
    if (std::cin >> in) {
      if (ptr < buffer + max - 1) {
        if (in != '.') {
          *ptr = in;
          ptr++;
        } else {
          break;
        }
      }
    }
  }
  *ptr = '$';

  std::cout << buffer;
}

void mayuscula(char *&buffer) {
  char *ptr = buffer;
  char aux;
  while (true) {
    aux = *ptr;
    if (aux != '$') {
      aux = aux - 32;
      *ptr = aux;
      ptr++;
    } else {
      break;
    }
  }
}

int main() {
  int const max = 40;
  char *cad;
  ingresar(cad, max);
  std::cout<<"\n";
  mayuscula(cad);
  std::cout<< cad;
  return 0;
}
