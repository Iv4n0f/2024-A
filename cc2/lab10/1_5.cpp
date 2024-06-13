#include <fstream>
#include <iostream>
#include <vector>

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
      if (isDecimal) {
        digitsAfterDecimal++;
        result = result * 10 + (c - '0');
      } else {
        result = result * 10 + (c - '0');
      }
    } else if (c == '.' && !isDecimal) {
      isDecimal = true;
      decimalPosition = digitsAfterDecimal;
    } else {
      cout << "No valid conversion to float";
      return -1;
    }
  }
  if (isDecimal) {
    float divisor = 1;
    for (int i = 0; i < digitsAfterDecimal; i++) {
      divisor *= 10;
    }
    result /= divisor;
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

void readFile(string filename, vector<Coord> &v) {
  ifstream file(filename);
  string line;
  if (!file.is_open()) {
    cerr << "No se puede abrir el archivo: " << filename << endl;
  }
  while (getline(file, line)) {
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
    v.push_back(coord);
  }
  file.close();
}

void print(vector<Coord> v) {
  for (Coord c : v) {
    cout << "(" << c.x << ", " << c.y << ")" << endl;
  }
}

void printOne(Coord c) { cout << "(" << c.x << ", " << c.y << ")" << endl; }

int partition(vector<Coord> &v, int low, int high) {
  float pivot = v[high].x;
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (v[j].x < pivot) {
      i++;
      swap(v[i], v[j]);
    }
  }
  swap(v[i + 1], v[high]);
  return (i + 1);
}

void quickSort(vector<Coord> &v, int low, int high) {
  if (low < high) {
    int pi = partition(v, low, high);
    quickSort(v, low, pi - 1);
    quickSort(v, pi + 1, high);
  }
}

int main() {
  vector<Coord> v;
  readFile("text.txt", v);
  quickSort(v, 0, v.size() - 1);
  printOne(v[0]);
  printOne(v[1]);
}

