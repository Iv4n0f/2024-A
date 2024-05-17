#include <iostream>

class Superior{
public:
  void print(){
    std::cout<<"Superior\n";
  }
};

class Inferior : public Superior{
public:
  void print(){
    std::cout<<"Inferior\n";
  }
};

int main(){
  Superior s;
  Inferior i;

  std::cout<<"Print superior: ";
  s.print();
  std::cout<<"Print inferior: ";
  i.print();
  std::cout<<"Print superior desde inferior: ";
  i.Superior::print();
}
