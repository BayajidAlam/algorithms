#include <bits/stdc++.h>
using namespace std;

// num of row,col
int n, m;
char a[20][20];
bool vis[20][20];

// set up,down,left,right value
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

// check is i,j valid
bool valid(int i, int j)
{
  if (i < 0 || i >= n || j < 0 || j >= m)
    return false;
  else
    return true;
}

// dfs func
void dfs(int si, int sj)
{
  cout << si << " " << sj << endl;
  // set src = true on vis
  vis[si][sj] = true;
  for (int i = 0; i < 4; i++)
  {
    // get the i,j of children
    int ci = si + d[i].first;
    int cj = sj + d[i].second;
    // check is ci,cj valid and visited = false
    if (valid(ci, cj) && vis[ci][cj] == false)
    {
      dfs(ci, cj);
    }
  }
}

int main()
{

  // input row,col
  cin >> n >> m;

  // input element of matrix
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  // input src i,j
  int si, sj;
  cin >> si >> sj;

  // set default values of visit
  memset(vis, false, sizeof(vis));

  // execute the dfs func
  dfs(si, sj);
  return 0;
}