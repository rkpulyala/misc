#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

vector<int> getRandomVector(int range_low, int range_high, int size)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(range_low, range_high);

    vector<int> v;
 
    for (int n=0; n<size; ++n)
        v.push_back(dis(gen));

    return v;
}

void right_rotate ( vector<int> &numbers, int start, int end) {
    int t = numbers[end];
    for(int i = start; i <= end; ++i) {
      swap(numbers[i],t);
    }
}


vector<int> altSort(vector<int> &numbers)
{
#if 0
  vector<int> result;
  int pos = 0, neg = 0;

  while (true) {
    while( pos < numbers.size() && numbers[pos] < 0 ) ++pos;
    if (pos < numbers.size()) result.push_back(numbers[pos++]);
    while( neg < numbers.size() && numbers[neg] > 0 ) ++neg;
    if (neg < numbers.size()) result.push_back(numbers[neg++]);
    if ( result.size() ==  numbers.size() ) break;
  }

  return result;
#endif

  int start = 0;

  for(int start = 0, end = start+1; start < numbers.size(); ++start, end = start+1) {
    if ( start%2 == 0 ) {
      if ( numbers[start] >= 0 ) continue;
      while( end < numbers.size() && numbers[end] < 0 ) ++end;
    }
    else {
      if ( numbers[start] < 0 ) continue;
      while( end < numbers.size() && numbers[end] >= 0 ) ++end;
    }
    if ( end >= numbers.size() ) break;
    right_rotate(numbers, start, end);
  }

  return numbers;

}

int main()
{
  vector<int> nums = getRandomVector( -100, -1, 10);
  auto pnums = getRandomVector( 0, 100, 10);
  nums.insert(nums.end(), pnums.begin(), pnums.end());
  for(auto n : nums) cout << n << " "; cout << endl;
  random_shuffle(nums.begin(), nums.end());
  for(auto n : nums) cout << n << endl;
  //right_rotate(nums, 0, nums.size()-1);
  //for(auto n : nums) cout << n << " "; cout << endl;
  altSort(nums);
  for(auto n : altSort(nums)) cout << n << " "; cout << endl;
  return 0;
}
