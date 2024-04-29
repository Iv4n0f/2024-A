#include <iostream>

// 0:c1>c2  1:c1 = c2 2:c1<c2
int comparar(char *c1, char *c2) {
  char *p1 = c1;
  char *p2 = c2;

  while (*p1 != '\0' && *p2 != '\0') {
    if (*p1 == *p2) {
      p1++;
      p2++;
      continue;
    }
    if (*p1 > *p2) {
      return 0;
    }
    if (*p1 < *p2) {
      return 2;
    }
  }

  if (*p1 != '\0')
    return 0;
  if (*p2 != '\0')
    return 2;
  return 1;
}

int main(){
  char c1 [] = {"abcd"};
  char c2 [] = {"abcd"};
  std::cout<<"comparando\n"<<c1<<'\n'<<c2 <<'\n';
  std::cout << comparar(c1,c2);
}
