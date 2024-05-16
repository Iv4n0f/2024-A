#include <iostream>
#include <vector>

template <typename T> class NodoArbol {
public:
  T dato;
  NodoArbol *izquierda;
  NodoArbol *derecha;

  NodoArbol(T valor) : dato(valor), izquierda(nullptr), derecha(nullptr) {}
};

template <typename T> class ArbolBinario {
private:
  NodoArbol<T> *raiz;
  std::vector<NodoArbol<T> *> nodosHijos;

  void insertarRecursivo(NodoArbol<T> *&nodo, T valor) {
    if (nodo == nullptr) {
      nodo = new NodoArbol<T>(valor);
      nodosHijos.push_back(nodo);
    } else if (valor < nodo->dato) {
      insertarRecursivo(nodo->izquierda, valor);
    } else {
      insertarRecursivo(nodo->derecha, valor);
    }
  }

void imprimirRecursivo(NodoArbol<T> *nodo, int nivel) {
    if (nodo == nullptr)
        return;

    imprimirRecursivo(nodo->derecha, nivel + 1);

    for (int i = 0; i < nivel; i++)
        std::cout << "  "; 

    std::cout << "|-" << nodo->dato << std::endl; 

    imprimirRecursivo(nodo->izquierda, nivel + 1);
}

public:
  ArbolBinario() : raiz(nullptr) {}

  void insertar(T valor) { insertarRecursivo(raiz, valor); }

  void mostrarArbol() { imprimirRecursivo(raiz, 0); }

  std::vector<NodoArbol<T> *> obtenerNodosHijos() { return nodosHijos; }
};

template<typename T>
bool find(const std::vector<T>& vec, const T& value) {
    for (const auto& element : vec) {
        if (element == value) {
            return true;
        }
    }
    return false;
}

int main() {
  srand(time(NULL));
  ArbolBinario<int> arbolInt;
  std::vector<int> datosInsertados;

  for (int i = 0; i < 1000; i++) {
    int dato = rand() % 2000 + 1;
    if (!find(datosInsertados,dato)){
      datosInsertados.push_back(dato);
      arbolInt.insertar(dato);
    }
  }

  arbolInt.mostrarArbol();
}
