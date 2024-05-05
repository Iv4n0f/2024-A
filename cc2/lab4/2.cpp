#include <iostream>
#include <vector>

using namespace std;

void llenar(vector<int> &v) {
  srand(time(NULL));
  for (int i = 0; i < 1000;i++) {
    v.push_back(rand() % 1000 + 1);
  }
}

void mostrar(vector<int> v){
  for(int i = 0; i<v.size();i++){
    cout << v[i]<<" ";
  }
  cout <<endl;
}

bool in(int k, vector<int> v){
  for(int i = 0; i<v.size();i++){
    if(v[i] == k) return true;
  }
  return false;
}

vector<int> eliminar_duplicados(vector<int> v){
  vector<int> duplicados;
  for(int i = 0; i<v.size();i++){
    if(in(v[i],duplicados)) continue;
    duplicados.push_back(v[i]);
  }
  return duplicados;
}

int main(){
  vector<int> v;
  llenar(v);
  cout<<"Sin procesar:"<<endl;
  mostrar(v);
  cout <<"________________"<<endl;
  vector<int> dup = eliminar_duplicados(v);
  cout<<"Duplicados eliminados:"<<endl;
  mostrar(dup);
}
