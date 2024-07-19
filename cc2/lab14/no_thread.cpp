#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>

int **generar_matriz() {
  int **matriz = new int *[1000];
  for (int i = 0; i < 1000; i++) {
    matriz[i] = new int[1000];
  }
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      matriz[i][j] = rand() % 10;
    }
  }
  return matriz;
}

int **suma(int **m1, int **m2) {
  int **result = new int *[1000];
  for (int i = 0; i < 1000; i++) {
    result[i] = new int[1000];
  }
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      result[i][j] = m1[i][j] + m2[i][j];
    }
  }
  return result;
}

int **multiplicacion(int **m1, int **m2) {
  int **result = new int *[1000];
  for (int i = 0; i < 1000; i++) {
    result[i] = new int[1000];
  }
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      int val = 0;
      for (int k = 0; k < 1000; k++) {
        val += m1[i][k] * m2[k][j];
      }
      result[i][j] = val;
    }
  }
  return result;
}

void print(int **matriz) {
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      std::cout << matriz[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  srand(time(NULL));
  int **m1 = generar_matriz();
  int **m2 = generar_matriz();

  auto start = std::chrono::high_resolution_clock::now();
  int **sum = suma(m1, m2);
  auto end = std::chrono::high_resolution_clock::now();

  auto start1 = std::chrono::high_resolution_clock::now();
  int **mult = multiplicacion(m1, m2);
  auto end1 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> duration_sum = end - start;
  std::chrono::duration<double> duration_mult = end1 - start1;

  std::cout << "\nSuma: " << duration_sum.count() * 1000
       << " milliseconds" << std::endl;
  std::cout << "\nMultiplicacion : " << duration_mult.count() * 1000
       << " milliseconds" << std::endl;
}
