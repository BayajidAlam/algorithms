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
    // input vertices and assign their value as 1 on ab and ba
    int a, b;
    cin >> a >> b;

    // remember: directed graph have only one direction
    mat[a][b] = 1;
    mat[b][a] = 1;
  }
  
  // print
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}