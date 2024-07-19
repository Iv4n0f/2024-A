#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>

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

void suma_threads(int **m1, int **m2, int **&result, int start, int end) {
  for (int i = start; i < end; i++) {
    for (int j = 0; j < 1000; j++) {
      result[i][j] = m1[i][j] + m2[i][j];
    }
  }
}

void multiplication_threads(int **m1, int **m2, int **&result, int start,
                            int end) {
  for (int i = start; i < end; i++) {
    for (int j = 0; j < 1000; j++) {
      int val = 0;
      for (int k = 0; k < 1000; k++) {
        val += m1[i][k] * m2[k][j];
      }
      result[i][j] = val;
    }
  }
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

  // Suma
  auto start = std::chrono::high_resolution_clock::now();
  int **sum = new int *[1000];
  for (int i = 0; i < 1000; i++) {
    sum[i] = new int[1000];
  }

  std::thread t_array_sum[8];

  int k = 0;
  for (int i = 0; i < 1000; i += 125) {
    t_array_sum[k] =
        std::thread(suma_threads, m1, m2, std::ref(sum), i, i + 125);
    k++;
  }
  for (int i = 0; i < 8; i++) {
    t_array_sum[i].join();
  }

  auto end = std::chrono::high_resolution_clock::now();

  // Multiplicacion
  auto start1 = std::chrono::high_resolution_clock::now();
  int **mult = new int *[1000];
  for (int i = 0; i < 1000; i++) {
    mult[i] = new int[1000];
  }

  std::thread t_array[8];

  int j = 0;
  for (int i = 0; i < 1000; i += 125) {
    t_array[j] =
        std::thread(multiplication_threads, m1, m2, std::ref(mult), i, i + 125);
    j++;
  }
  for (int i = 0; i < 8; i++) {
    t_array[i].join();
  }

  auto end1 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> duration_sum = end - start;
  std::chrono::duration<double> duration_mult = end1 - start1;

  std::cout << "\nSuma: " << duration_sum.count() * 1000 << " milliseconds"
            << std::endl;
  std::cout << "\nMultiplicacion : " << duration_mult.count() * 1000
            << " milliseconds" << std::endl;
}
