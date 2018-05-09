#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

unsigned int reverse(unsigned int n)
{
    int r = 0;
    while(n) {
      r = r*10 + n%10;
      n/=10;
    }
    return r;
}

unsigned int digitAt(unsigned int n, int index)
{
  return static_cast<int>(n/pow(10,index)) % 10;
}

unsigned int nextPalindromicNumber(unsigned int n)
{
  if (reverse(n) == n ) ++n;
  unsigned int right = 0, left = log10(n);
  unsigned long result = 0,
  
  while( right < left ) {
    if ( digitAt(n,right) > digitAt(n,left)  ) {
      n += pow(10, right+1);
    }
    result += digitAt(n,left) * pow(10, right);
    ++right;
    --left;
    cout << n << " " << result << endl;
  }

  result += n - n%static_cast<int>(pow(10,right));

  //for(int i = 0; i <= left; ++i ) cout << digitAt(n, i) << " "; cout << endl;
  return result;
}

int main()
{
  unsigned int n = 371634;
  cin >> n;
  cout << "reverse = " << reverse(n) << endl;
  cout << "next palin = " << nextPalindromicNumber(n) << endl;
  return n;
}

