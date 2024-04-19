#include <iostream>

using namespace std;

long long *fun(){
  long long *ptr = new long long [10000];
  *ptr = 20;
  return ptr;
}

int main(){
  while(true){
    long long *p = fun();
    cout << *p << endl;
  }
}
