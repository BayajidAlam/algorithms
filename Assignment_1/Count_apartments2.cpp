#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1005][1005];
bool vis[1005][1005];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
  return (i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '.');
}

int dfs(int si, int sj)
{
  vis[si][sj] = true;
  int cnt = 1;

  for (int i = 0; i < 4; i++)
  {
    int ci = si + d[i].first;
    int cj = sj + d[i].second;

    if (isValid(ci, cj) && !vis[ci][cj])
    {
      cnt += dfs(ci, cj);
    }
  }

  return cnt;
}

int main()
{
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
      vis[i][j] = false;
    }
  }

  vector<int> rooms;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a[i][j] == '.' && !vis[i][j])
      {
        int cnt = dfs(i, j);
        rooms.push_back(cnt);
      }
    }
  }

  sort(rooms.begin(), rooms.end());

  for (int cnt : rooms)
  {
    cout << cnt << " ";
  }

  if (rooms.empty())
  {
    cout << "0";
  }

  return 0;
}
