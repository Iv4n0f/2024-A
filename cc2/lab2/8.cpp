#include <ctime>
#include <iostream>

using namespace std;

void copiar(float *p1, float *&p2, int n) {
  p2 = new float[n];

  for (int i = 0; i < n; i++) {
    p2[i] = p1[i];
  }
}

void print(float *p, int n) {
  for (int i = 0; i < n; i++) {
    cout << p[i] << " - ";
  }
}

int main() {
  int n = 5;
  float *p1;
  p1 = new float[n];
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    p1[i] = rand() % 5;
  }
  cout << "Original =";
  print(p1,n);

  float *p2;
  copiar(p1,p2,n);
  cout<<"\n Copia = ";
  print(p2,n);

}
