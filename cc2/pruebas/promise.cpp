#include <future>
#include <iostream>
using namespace std;
int main() {
  std::promise<int> pr;
  auto fut1 = pr.get_future();
  try {
    auto fut2 = pr.get_future();
    return 0;
  } catch (const std::future_error &e) {
    cout << e.what() << endl;
    return -1;
  }
  return 0;
}
