#include <iostream>
#include <chrono>

using namespace std;

int ***generarMatriz() {
  int ***v;
  v = new int **[1000];
  for (int i = 0; i < 1000; i++) {
    v[i] = new int *[1000];
    for (int j = 0; j < 1000; j++) {
      v[i][j] = new int[3];
    }
  }
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      for (int k = 0; k < 3; k++) {
        v[i][j][k] = 1;
      }
    }
  }
  return v;
}

int ***sumar(int ***v1, int ***v2) {
  int ***v;
  v = new int **[1000];
  for (int i = 0; i < 1000; i++) {
    v[i] = new int *[1000];
    for (int j = 0; j < 1000; j++) {
      v[i][j] = new int[3];
    }
  }
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      for (int k = 0; k < 3; k++) {
        v[i][j][k] = 0;
      }
    }
  }
  // Suma:
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      for (int k = 0; k < 3; k++) {
        v[i][j][k] = v1[i][j][k] + v2[i][j][k];
      }
    }
  }

  return v;
}

int main() {
  auto start = chrono::high_resolution_clock::now();
  int ***v1 = generarMatriz();
  int ***v2 = generarMatriz();

  int ***v = sumar(v1, v2);
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
  cout<< duration.count()<<"ms"<<endl;
  cout << v[0][0][0];
}
