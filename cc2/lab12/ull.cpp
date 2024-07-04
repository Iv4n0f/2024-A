#include <chrono>
#include <fstream>
#include <iostream>
#include <memory>
#include <utility>
using namespace std;

struct nodo {
  float num;
  std::unique_ptr<nodo> sig;
};
typedef nodo nodo;

class List {
private:
  std::unique_ptr<nodo> L;
  float min;

public:
  List() { L = nullptr; }

  void insertar(float num) {
    std::unique_ptr<nodo> temp = std::make_unique<nodo>();
    temp->num = num;
    temp->sig = nullptr;

    // Lista vacia
    if (!L || num <= L->num) {
      temp->sig = std::move(L);
      L = std::move(temp);
      return;
    }

    // Insertar en orden
    nodo *actual = L.get();
    while (actual->sig && num > actual->sig->num) {
      actual = actual->sig.get();
    }
    temp->sig = std::move(actual->sig);
    actual->sig = std::move(temp);
  }

  void print() {
    nodo *temp = L.get();
    std::cout << "\nPrimer numero: " << temp->num << std::endl;
    while (temp->sig != NULL) {
      temp = temp->sig.get();
    }
    std::cout << "Ultimo numero: " << temp->num << std::endl;
  }

  void eliminar(float num) {
    std::unique_ptr<nodo> actual = std::move(L);
    std::unique_ptr<nodo> anterior = NULL;
    // Primer elemento
    if (actual != NULL && actual->num == num) {
      L = std::move(actual->sig);
      actual.reset();
      return;
    }
    // Buscar elemento a eliminar
    while (actual != NULL && actual->num != num) {
      anterior = std::move(actual);
      actual = std::move(actual->sig);
    }
    if (actual != NULL) {
      anterior->sig = std::move(actual->sig);
      actual.reset();
    }
  }

  bool buscar(float num) {
    std::unique_ptr<nodo> actual = std::move(L);
    int index = 0;
    while (actual != NULL && actual->num != num) {
      actual = std::move(actual->sig);
      index++;
    }
    if (actual != NULL) {
      cout << "\n[" << index << "] " << actual->num;
      return true;
    } else {
      cout << "\nEl número no se encuentra en la lista.";
      return false;
    }
  }
};

float stringToFloat(const string &str) {
  float result = 0.0;
  int decimalPosition = -1;
  bool isDecimal = false;
  int digitsAfterDecimal = 0;
  bool isNegative = false;
  int start = 0;
  if (str[0] == '-') {
    isNegative = true;
    start = 1;
  }
  for (int i = start; i < str.length(); i++) {
    char c = str[i];
    if (c >= '0' && c <= '9') {
      result = result * 10 + (c - '0');
      if (isDecimal) {
        digitsAfterDecimal++;
      }
    } else if (c == '.' && !isDecimal) {
      isDecimal = true;
    } else {
      cout << "No valid conversion to float";
      return -1;
    }
  }
  if (isDecimal) {
    for (int i = 0; i < digitsAfterDecimal; i++) {
      result /= 10;
    }
  }
  if (isNegative) {
    result = -result;
  }
  return result;
}

void readFile(string filename, List &list, float leidos) {
  ifstream file(filename);
  string line;
  if (!file.is_open()) {
    cerr << "No se puede abrir el archivo: " << filename << endl;
  }
  int c = 0;
  while (getline(file, line) && c < leidos) {
    string number = "";
    bool x_filled = false;
    for (char c : line) {
      if (c != ',' && c != ' ') {
        number += c;
      } else {
        if (!x_filled) {
          x_filled = true;
          number = "";
        }
      }
    }
    list.insertar(stringToFloat(number)); // number = y
    c++;
    // cout << "\rInserciones: " << c << " / " << leidos;
  }
  file.close();
}

int main() {
  List L;

  const float leidos = 500000;

  auto start = chrono::high_resolution_clock::now();
  readFile("text.txt", L, leidos);
  auto end = chrono::high_resolution_clock::now();

  cout << endl;
  cout<<"Analizando "<< leidos <<"datos"<<endl;
  L.print();

  chrono::duration<double> duration = end - start;

  cout << "\nTiempo de ejecucion: " << duration.count() * 1000
       << " milliseconds" << endl;
}
