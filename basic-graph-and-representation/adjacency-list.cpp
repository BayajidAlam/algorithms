#include <bits/stdc++.h>
using namespace std;

int main()
{
  // input node and edge
  int n, e;
  cin >> n >> e;

  // initialize a matrix that contain vector of int
  vector<int> mat[n];
  while (e--)
  {
    // input a,b
    int a, b;
    cin >> a >> b;
    // connection
    mat[a].push_back(b);
    // ignore this if graph is directed
    mat[b].push_back(a);
  }
  // print
  for (int i = 0; i < mat[3].size(); i++)
  {
    cout <<mat[3][i] << " ";
  }
  return 0;
}