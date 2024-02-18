#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
  if (i < 0 || i >= n || j < 0 || j >= m)
    return false;
  if (a[i][j] == '-' || vis[i][j])
    return false;
  return true;
}

int bfs(int si, int sj)
{
  queue<pair<int, int>> q;
  q.push({si, sj});
  vis[si][sj] = true;
  int area = 0;

  while (!q.empty())
  {
    pair<int, int> par = q.front();
    q.pop();
    area++;

    for (int i = 0; i < 4; i++)
    {
      int ci = par.first + d[i].first;
      int cj = par.second + d[i].second;

      if (valid(ci, cj))
      {
        q.push({ci, cj});
        vis[ci][cj] = true;
      }
    }
  }
  return area;
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

  int min_area = INT_MAX;
  bool found = false;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a[i][j] == '.' && !vis[i][j])
      {
        found = true;
        min_area = min(min_area, bfs(i, j));
      }
    }
  }

  if (found)
    cout << min_area << endl;
  else
    cout << -1 << endl;

  return 0;
}