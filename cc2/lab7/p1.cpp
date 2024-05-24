#include <iostream>
#include <vector>

using namespace std;

template <typename T> class Vector {
private:
  vector<T> v;
public:
  Vector() = default;

  void operator,(const T& element){
    v.push_back(element);
  }

  void print() const{
    for(T element:v){
      cout<<element<<", ";
    }
    cout<<endl;
  }
};

int main(){
  Vector<int> v;
  v,10,12,22;
  v.print();
}
