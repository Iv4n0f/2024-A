#include <iostream>

struct nodo {
  int num;
  nodo *sig;
};
typedef nodo *Nodo;

void insertar(int num, Nodo &Lista, int &minimo) {
  Nodo temp = new nodo;
  temp->num = num;
  temp->sig = NULL;

  if (Lista == NULL) {
    Lista = temp;
    minimo = num;
    return;
  }

  if (num <= minimo) { // Instertar al principio
    temp->sig = Lista;
    Lista = temp;
    minimo = num;
  } else { // Insertar en la segunda posicion
    if (Lista->sig == NULL) {
      Lista->sig = temp;
    } else {
      temp->sig = Lista->sig;
      Lista->sig = temp;
    }
  }
//  std::cout << "Nodo insertado\n";
}

void print(Nodo Lista) {
  Nodo temp = Lista;
  while (temp != NULL) {
    std::cout << temp->num << "->";
    temp = temp->sig;
  }
  std::cout << "NULL" << std::endl;
}

int main() {
  Nodo L = NULL;
  int min;
  for (int i = 0; i < 8; i++) {
    int n;
    std::cout << "Numero:";
    std::cin >> n;
    insertar(n, L, min);
    print(L);
  }
  return 0;
}
