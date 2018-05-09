#include <iostream>



struct A {
  static int func(int a, int b) {   return a + b; }
  int v = func(10, 20);
  const int val() const { return v; }
};

int main()
{
  A a;
  std::cout<< a.val() << std::endl;
  return 0;
}
