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
  } else { // Insertar en donde mayor al anterior
    if (Lista->sig == NULL) {
      Lista->sig = temp;
    } else {
      //     temp->sig = Lista->sig;
      //     Lista->sig = temp;
      Nodo actual= Lista->sig;
      Nodo anterior = Lista;
      while (temp->num > actual->num) {
        if (actual->sig != NULL) {
          anterior = actual;
          actual = actual->sig;
        }
        else {
          anterior = actual;
          break;}
      }
        temp->sig = anterior->sig;
        anterior->sig = temp;
    }
  }
}


void solicitar(Nodo &Lista){
  Lista = Lista->sig;
  std::cout << "Solicitado: " <<Lista ->num;
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
