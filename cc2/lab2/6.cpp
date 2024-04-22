#include <ctime>
#include <iostream>

using namespace std;

void doslistas(int *&p1, int *&p2, int n) {
  srand(time(NULL));
  p1 = new int[n];
  p2 = new int[n];

  for (int i = 0; i < n; i++) {
    p1[i] = rand() % 100;
    p2[i] = rand() % 100;
  }
}

void print(int*p, int n){ 
  for (int i = 0; i < n; i++) {
    cout<<p[i]<<"-";
  }
}

void intercambio(int*&p1,int*&p2){
  int*aux = p1;
  p1 = p2;
  p2 = aux;
}

int main(){
  int * p1;
  int * p2;
  int n = 5;
  doslistas(p1,p2,n); 

  cout<<"Cont. p1 = ";
  print(p1,5);
  cout<<"Cont. p2 = ";
  print(p2,5);
  
  intercambio(p1,p2);
  cout <<endl;

  cout<<"Cont. p1 = ";
  print(p1,5);
  cout<<"Cont. p2 = ";
  print(p2,5);

}
