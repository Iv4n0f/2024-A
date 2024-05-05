#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void llenar(vector<int> &v) {
  srand(time(NULL));
  for (int i = 0; i < 1000; i++) {
    v.push_back(rand() % 1000 + 1);
  }
}

void mostrar(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

vector<int> ordenar(vector<int> v) {
  int aux;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size() - 1 - i; j++) {
      if (v[j] > v[j + 1]) {
        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
      }
    }
  }
  return v;
}

vector<int> k_menores(int k, vector<int> v) {
  vector<int> temp = ordenar(v);
  vector<int> km;
  for (int i = 0; i<k-1;i++) {
    km.push_back(temp[i]);
  }
  return km;
}

int main() {
  vector<int> v;
  llenar(v);
  vector<int> kmenores = k_menores(30, v);
  mostrar(kmenores);
}
