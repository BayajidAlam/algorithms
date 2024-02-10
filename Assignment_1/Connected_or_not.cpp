#include <bits/stdc++.h>
using namespace std;
int main()
{
  // input node and edge
  int n, e;
  cin >> n >> e;
  // initialize a matrix
  int mat[n][n];
  // set default value 0
  memset(mat, 0, sizeof(mat));

  while (e--)
  {
    // input vertices and assign their value as 1
    int a, b;
    cin >> a >> b;
    mat[a][b] = 1;
  }
  // input queries 
  int tt;
  cin >> tt;
  while (tt--)
  {
    // check connection
    int a, b;
    cin >> a >> b;
    if (a == b || mat[a][b] == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
