#include <iostream>
#include <vector>
#include <queue>

struct Building
{
  int start;
  int end;
  int height;
};

struct Skyline
{
  int pos;
  int height;
};

using namespace std;

vector<Skyline> buildSkyline( vector<Building> &buildings )
{
  struct 

  sort(buildings.begin(), buildings.end(), [](Building &left, Building &right){ 
      return left.start < right.start; 
      });

  for(auto &b : buildings) cout << b.start << " " << b.end << endl;

  vector<Skyline> skyline;

  return skyline;
}


int main()
{
  vector<Building> buildings;

  do {
    Building b;
    cin >> b.start >> b.end >> b.height;
    if (b.start == 0 && b.end == 0) break;
    buildings.push_back(b);
  }while(1);

  auto skyline = buildSkyline(buildings);

  for(auto &s : skyline) cout << s.pos << " " << s.height << endl;

  return 0;
}
