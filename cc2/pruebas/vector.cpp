#include <cmath>
#include <iostream>

using namespace std;

class Point {
protected:
  int x, y;

public:
  Point() { x = y = 0; }
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
  int getX() const { return x; }
  int getY() const { return y; }
  void setX(int x) { this->x = x; }
  void setY(int y) { this->y = y; }
};

class Vector : public Point {
private:
  Point i, f;
  float mod;

public:
  Vector(Point _i, Point _f) {
    i = _i;
    f = _f;
    int c1, c2;
    c1 = f.getX() - i.getX();
    c2 = f.getY() - i.getY();
    mod = sqrt(c1 * c1 + c2 * c2);
  }
  Point getI() const { return i; }
  Point getF() const { return f; }
  void setI(Point _i) { i = _i; }
  void setF(Point _f) { f = _f; }
  float getMod() const { return mod;}

  void print(){
    cout <<"P1("<<i.getX()<<","<<i.getY()<<")";
    cout <<"P2("<<f.getX()<<","<<f.getY()<<")";
  }
};

int main(){
  
}
