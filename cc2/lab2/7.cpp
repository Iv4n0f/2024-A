#include <iostream>

using namespace std;

void print(float *p, int n) {
  for (int i = 0; i < n; i++) {
    cout << p[i] << " - ";
  }
}

void ingresar(float *&p,int n, float num) {
  for (int i = 0; i < n; i++) {
    if (p[i] == 0) {
      p[i] = num;
      return;
    }
  }
}

int main() {
  int n = 5;
  float *p = new float[n]; 
  
  float num;
  for (int i = 0; i < n; i++) {
    cout<<"Ingresar = ";
    cin >> num;
    ingresar(p,n,num);
  }
  print(p, n);
}
