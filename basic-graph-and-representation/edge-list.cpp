#include <bits/stdc++.h>
using namespace std;

int main()
{

  int n, e;
  cin >> n >> e;
  vector<pair<int, int>> v;
  while (e--)
  {
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
    // alternative
    // v.push_back({a, b});
  }

  // print
  // for (int i = 0; i < v.size(); i++)
  // {
  //   cout << v[i].first << " " << v[i].second << endl;
  // }

  // another way to print
  // for (pair<int, int> pr : v)
  // {
  //   cout << pr.first << " " << pr.second << endl;
  // }

  // another way to print
  for (auto pr : v)
  {
    cout << pr.first << " " << pr.second << endl;
  }
  return 0;
}