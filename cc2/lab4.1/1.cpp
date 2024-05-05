#include <bits/chrono.h>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<vector<vector<int>>> generarMatriz() {
  vector<vector<vector<int>>> v(1000,
                                vector<vector<int>>(1000, vector<int>(3, 1)));
  return v;
};

vector<vector<vector<int>>> suma(vector<vector<vector<int>>> v1,
                                 vector<vector<vector<int>>> v2) {
  vector<vector<vector<int>>> sum(1000,
                                  vector<vector<int>>(1000, vector<int>(3, 0)));
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      for (int k = 0; k < 3; k++) {
        sum[i][j][k] = v1[i][j][k] + v2[i][j][k];
      }
    }
  }
  return sum;
}

int main() {
  auto start = chrono::high_resolution_clock::now();
  vector<vector<vector<int>>> v1 = generarMatriz();
  vector<vector<vector<int>>> v2 = generarMatriz();

  vector<vector<vector<int>>> sum = suma(v1, v2);
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
  cout<< duration.count()<<"ms"<<endl;
  cout << sum[0][0][0];
}

