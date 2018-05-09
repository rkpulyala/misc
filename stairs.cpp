#include <iostream>

using namespace std;

int stairs(int nbricks, int height)
{
  int sum = 0;
  if ( height == 0 || nbricks <= 0 ) sum = 0;
  else if ( nbricks == 1 || nbricks == 2 ) sum = 1;
  else {
    for(int i = height; i > 1 ; --i)
      sum += stairs(nbricks-i, i-1);
  }
  cout << nbricks << " " << height << " : "  << sum << endl;
  return sum;
}

int main()
{
  cout<< stairs(10,9) << endl;
  return 0;
}
