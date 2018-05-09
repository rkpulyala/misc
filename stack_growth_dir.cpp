#include <iostream>

using namespace std;

bool isGrowUpStack()
{
#if 0
  int i=0;
  cout << &i << endl;
  {
    int j = 9;
    cout << &j << endl;
    if ( &i - &j < 0 ) return true;
  }

  return false;
#endif

  int i=0;
  cout << &i << endl;
  int j = 9;
  cout << &j << endl;
  if ( &i - &j < 0 ) return true;
  return false;
}

int main()
{
  std::cout<< isGrowUpStack() << std::endl;
  return 0;
}
