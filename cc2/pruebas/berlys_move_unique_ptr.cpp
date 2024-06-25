#include <iostream>
#include <memory>

using namespace std;

auto f(unique_ptr<int> &&ptr)->unique_ptr<int>{
  *ptr = 42;
  return ptr;
}

int main() {
  auto ptr = make_unique<int>();
  cout << *ptr;
  ptr = f(std::move(ptr));
  cout << *ptr;
}
