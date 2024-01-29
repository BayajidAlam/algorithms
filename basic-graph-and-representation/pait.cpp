#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
  int first, second;
  Pair(int first, int second)
  {
    this->first = first;
    this->second = second;
  }
};

int main()
{
  Pair p(10, 20);
  cout << p.first << " " << p.second << endl;
  return 0;
}