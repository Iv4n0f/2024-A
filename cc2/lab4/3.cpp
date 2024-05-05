#include <iostream>
#include <vector>

using namespace std;

struct par {
  int x, y;
};

void ordenar(vector<par> &v) {
  par aux;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size() - 1 - i; j++) {
      if (v[j].x > v[j + 1].x) {
        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
      }
    }
  }
}

void mostrar(vector<par> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << "(" << v[i].x << "," << v[i].y << ") ";
  }
  cout << endl;
}

void unirIntervalos(vector<par> &v) {
  ordenar(v);
  for (int i = v.size() - 1; i > 0; i--) {
    if (v[i].x <= v[i - 1].y) {
      v[i - 1].y = v[i].y;
      v.erase(v.begin() + i);
    }
  }
}

int main() {
  vector<par> v = {{15, 32}, {12, 20}, {100, 200}, {45, 89}, {90, 110}};
  mostrar(v);
  unirIntervalos(v);
  mostrar(v);
}
