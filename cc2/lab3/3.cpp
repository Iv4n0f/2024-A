#include <iostream>

char vocales[] = {'a', 'e', 'i', 'o', 'u'};

bool es_vocal(char c) {
  for (int i = 0; i < 5; i++) {
    if (c == vocales[i])
      return true;
  }
  return false;
}

void modificar(char *&cad) {
  char *ptr = cad;
  while (*ptr != '\0') {
    if (es_vocal(*ptr)) {
      *ptr = 'X';
    }
    ptr++;
  }
}

int main() {
  char *cad;
  cad = new char[100];
  const char *cadenaInicial = "prueba";
  int i = 0;
  while (cadenaInicial[i] != '\0') {
    cad[i] = cadenaInicial[i];
    i++;
  }
  cad[i] = '\0';

  std::cout << cad << '\n';
  modificar(cad);
  std::cout << cad << '\n';
  delete[] cad;
}
