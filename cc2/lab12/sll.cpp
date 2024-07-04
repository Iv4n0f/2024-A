#include <chrono>
#include <fstream>
#include <iostream>
#include <memory>
using namespace std;

struct nodo {
  float num;
  std::shared_ptr<nodo> sig;
};
typedef nodo nodo;

class List {
private:
  std::shared_ptr<nodo> L;
  float min;

public:
  List() { L = NULL; }

  void insertar(float num) {
    std::shared_ptr<nodo> temp = std::make_shared<nodo>();
    temp->num = num;
    temp->sig = NULL;
    // Lista vacia
    if (L == NULL) {
      L = temp;
      min = num;
      return;
    }
    // Menor o igual al primero
    if (num <= min) {
      temp->sig = L;
      L = temp;
      min = num;
      return;
    }
    // Otros casos
    std::shared_ptr<nodo> actual = L;
    std::shared_ptr<nodo> anterior = NULL;
    while (actual != NULL && actual->num < num) {
      anterior = actual;
      actual = actual->sig;
    }
    anterior->sig = temp;
    temp->sig = actual;
  }

  void print() {
    std::shared_ptr<nodo> temp = L;
    std::cout << "\nPrimer numero: " << temp->num << std::endl;
    while (temp->sig != NULL) {
      temp = temp->sig;
    }
    std::cout << "Ultimo numero: " << temp->num << std::endl;
  }

  void eliminar(float num) {
    std::shared_ptr<nodo> actual = L;
    std::shared_ptr<nodo> anterior = NULL;
    // Primer elemento
    if (actual != NULL && actual->num == num) {
      L = actual->sig;
      actual.reset();
      return;
    }
    // Buscar elemento a eliminar
    while (actual != NULL && actual->num != num) {
      anterior = actual;
      actual = actual->sig;
    }
    if (actual != NULL) {
      anterior->sig = actual->sig;
      actual.reset();
    }
  }

  bool buscar(float num) {
    std::shared_ptr<nodo> actual = L;
    int index = 0;
    while (actual != NULL && actual->num != num) {
      actual = actual->sig;
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
  readFile("text.txt", L,leidos);
  auto end = chrono::high_resolution_clock::now();

  cout << endl;
  cout<<"Analizando "<< leidos <<"datos"<<endl;
  L.print();

  chrono::duration<double> duration = end - start;

  cout << "\nTiempo de ejecucion: " << duration.count() * 1000
       << " milliseconds" << endl;
}
