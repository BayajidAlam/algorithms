#include <bits/stdc++.h>
using namespace std;

// num of row,col
int n, m;
char a[1005][1005];
bool vis[1005][1005];

// set up,down,left,right value
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

// check is i,j valid
bool valid(int i, int j)
{
  return (i >= 0 && i < n && j >= 0 && j < m);
}

// dfs func
void dfs(int si, int sj)
{
  // set src = true on vis
  vis[si][sj] = true;

  for (int i = 0; i < 4; i++)
  {
    // get the i,j of children
    int ci = si + d[i].first;
    int cj = sj + d[i].second;

    // check is ci,cj valid, not a wall, and visited = false
    if (valid(ci, cj) && a[ci][cj] == '.' && !vis[ci][cj])
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

  int cnt = 0;

  // iterate through all cells
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      // check if it's a room and not visited
      if (a[i][j] == '.' && !vis[i][j])
      {
        dfs(i, j);
        cnt++;
      }
    }
  }

  cout << cnt << endl;

  return 0;
}
