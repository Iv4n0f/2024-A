#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

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

typedef struct {
  float x;
  float y;
} Coord;

void readFile(string filename, Coord arr[], int &size) {
  ifstream file(filename);
  string line;
  if (!file.is_open()) {
    cerr << "No se puede abrir el archivo: " << filename << endl;
  }
  size = 0;
  while (getline(file, line) && size < 500000) {
    Coord coord;
    string number = "";
    bool x_filled = false;
    for (char c : line) {
      if (c != ',' && c != ' ') {
        number += c;
      } else {
        if (!x_filled) {
          coord.x = stringToFloat(number);
          x_filled = true;
          number = "";
        }
      }
    }
    coord.y = stringToFloat(number);
    arr[size++] = coord;
  }
  file.close();
}

void print(Coord arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << "(" << arr[i].x << ", " << arr[i].y << ")" << endl;
  }
}

void printOne(Coord &c) {
  cout << fixed << setprecision(6);
  cout << "(" << c.x << ", " << c.y << ")" << endl;
}

void sort(Coord arr[], int low, int high) {
  if (low < high) {
    float pivot = arr[high].x;
    int i = (low - 1);
    for (int j = low; j < high; j++) {
      if (arr[j].x < pivot) {
        i++;
        Coord temp = std::move(arr[i]);
        arr[i] = std::move(arr[j]);
        arr[j] = std::move(temp);
      }
    }
    Coord temp = std::move(arr[i + 1]);
    arr[i + 1] = std::move(arr[high]);
    arr[high] = std::move(temp);
    int pi = i + 1;
    sort(arr, low, pi - 1);
    sort(arr, pi + 1, high);
  }
}

int main() {
  const int MAX_SIZE = 500000;
  Coord arr[MAX_SIZE];
  int size = 0;

  readFile("text.txt", arr, size);

  cout << "Struct std::move()" << endl;
  cout << "arr[0] \t\t";
  printOne(arr[0]);
  cout << "arr[size-1] \t";
  printOne(arr[size - 1]);

  auto start = chrono::high_resolution_clock::now();
  sort(arr, 0, size - 1);
  auto end = chrono::high_resolution_clock::now();

  cout << endl;
  cout << "Ordenado: " << endl;
  cout << "arr[0] \t\t";
  printOne(arr[0]);
  cout << "arr[size-1] \t";
  printOne(arr[size - 1]);

  chrono::duration<double> duration = end - start;

  cout << "\nTiempo de ejecucion: " << duration.count() * 1000
       << " milliseconds" << endl;

  cout << "==========" << endl;
}
