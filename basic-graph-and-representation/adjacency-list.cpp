#include <bits/stdc++.h>
using namespace std;

int main()
{

  int n, e;
  cin >> n >> e;
  int arr[n];
  vector<int> mat[n];
  while (n--)
  {
    int a, b;
    cin >> a >> b;
    mat[a].push_back(b);
    mat[b].push_back(a);
  }
  for(int i=0; i<mat[0].size(); i++){
    cout << mat[0][i] << endl;
  }
  return 0;
}