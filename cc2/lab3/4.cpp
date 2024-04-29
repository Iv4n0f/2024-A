#include <iostream>

void concatenar(char *&c1,char*&c2){
  int lc1 = 0;
  while (c1[lc1] != '\0') {
    lc1++;
  }
  int lc2 = 0;
  while (c2[lc2] != '\0') {
    lc2++;
  }
  char * aux = new char[lc1+lc2+1];
  int c = 0;
  for(int i = 0; i < lc1; i++, c++){
    aux[c] = c1[i];
  }
  for(int i = 0; i < lc2; i++,c++){
    aux[c] = c2[i];
  }
  aux[c] = '\0';
  delete [] c1;
  c1 = aux;
}

void ingresar(char *&cad, const char *inicial) {
  cad = new char[100];
  int i = 0;
  while (inicial[i] != '\0') {
    cad[i] = inicial[i];
    i++;
  }
  cad[i] = '\0';
}

int main() {
  char *c1;
  ingresar(c1, "prueba");
  char * c2;
  ingresar(c2, "concatenacion");
  std::cout <<"C1= "<< c1 << '\n';
  std::cout <<"C2= "<< c2 << '\n';
  concatenar(c1,c2);
  std::cout <<"C1= "<< c1 << '\n';
  std::cout <<"C2= "<< c2 << '\n';
}
