#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;

struct nodo {
  float num;
  nodo *sig;
};
typedef nodo *Nodo;

class List {
private:
  Nodo L;
  float min;
  Nodo max;

public:
  List() { L = NULL; }

  void insertar(float num) {
    Nodo temp = new nodo;
    temp->num = num;
    temp->sig = NULL;
    //Lista vacia
    if (L == NULL) {
      L = temp;
      min = num;
      max = temp;
      return;
    }
    //Menor o igual al primero
    if (num <= min) {
      temp->sig = L;
      L = temp;
      min = num;
      return;
    }
    //Mayor al maximo
    if (num > max->num) {
      max->sig = temp;
      max = temp;
      return;
    }
    //Otros casos
    Nodo actual = L;
    Nodo anterior = NULL;
    while (actual != NULL && actual->num < num) {
      anterior = actual;
      actual = actual->sig;
    }
    anterior->sig = temp;
    temp->sig = actual;
  }

  void print() {
    Nodo temp = L;
    std::cout << "Primer numero: " << temp->num << std::endl;
    while (temp->sig != NULL) {
      temp = temp->sig;
    }
    std::cout << "Ultimo numero: " << temp->num << std::endl;
  }

  void eliminar(float num) {
    Nodo actual = L;
    Nodo anterior = NULL;
    if (actual != NULL && actual->num == num) {
      L = actual->sig;
      delete actual;
      return;
    }
    while (actual != NULL && actual->num != num) {
      anterior = actual;
      actual = actual->sig;
    }
    if (actual != NULL) {
      anterior->sig = actual->sig;
      if (actual == max) { 
        max = anterior;
      }
      delete actual;
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

void readFile(string filename, List &list) {
  ifstream file(filename);
  string line;
  if (!file.is_open()) {
    cerr << "No se puede abrir el archivo: " << filename << endl;
  }
  int c = 0;
  while (getline(file, line) && c < 100000) {
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
  }
  file.close();
}

int main() {
  List L;

  auto start = chrono::high_resolution_clock::now();
  readFile("text.txt", L);
  auto end = chrono::high_resolution_clock::now();

  L.print();

  chrono::duration<double> duration = end - start;

  cout << "\nTiempo de ejecucion: " << duration.count() * 1000
       << " milliseconds" << endl;
}
