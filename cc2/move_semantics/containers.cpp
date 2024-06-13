#include <iostream>
#include <vector>

void print(const std::vector<int> &vec)
{
  for (auto &&val : vec)
  {
    std::cout << val << ", ";
  }
  std::cout << std::endl;
}

int main()
{
  std::vector<int> vec1{1, 2, 3, 4};
  std::vector<int> vec2;
  print(vec1);
  print(vec2);
  vec2 = std::move(vec1);
  print(vec1);
  print(vec2);
}