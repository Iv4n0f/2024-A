#include <iostream>

using namespace std;

void fun(){
  int num = 2;
  int * ptr = &num;
  cout<<"Valor de num = "<<num<<" DM de num = "<<&num<<endl;
  cout<<"Valor de ptr = "<<ptr<<" DM de ptr = "<<&ptr<<endl;
}

int main(){
  fun();
}
