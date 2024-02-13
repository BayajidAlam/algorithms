#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
  return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int si, int sj)
{
  vis[si][sj] = true;
  for (int i = 0; i < 4; i++)
  {
    int ci = si + d[i].first;
    int cj = sj + d[i].second;
    if (valid(ci, cj) && !vis[ci][cj] && a[ci][cj] == '.')
    {
      dfs(ci, cj);
    }
  }
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  int si, sj;
  cin >> si >> sj;

  memset(vis, false, sizeof(vis));

  dfs(si, sj);

  int di, dj;
  cin >> di >> dj;
  
  if (vis[di][dj])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
