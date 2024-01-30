#include <bits/stdc++.h>
using namespace std;

char a[20][20];
bool vis[100][100];
int dis[100][100];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool is_valid(int i, int j)
{
  if (i < 0 || i >= n || j < 0 || j >= m)
    return false;
  else
    return true;
}

void bfs(int si, int sj)
{

  queue<pair<int, int>> q;
  q.push({si, sj});
  vis[si][sj] = true;
  dis[si][sj] = 0;

  while (!q.empty())
  {

    pair<int, int> pr = q.front();
    int a = pr.first;
    int b = pr.second;
    q.pop();

    cout << a << " " << b << endl;
    for (int i = 0; i < 4; i++)
    {

      int ci = a + d[i].first;
      int cj = b + d[i].second;

      if (is_valid(ci, cj) == true && vis[ci][cj] == false)
      {
        q.push({ci, cj});
        vis[ci][cj] = true;
        dis[ci][cj] = dis[a][b] + 1;
      }
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

  memset(vis, 0, sizeof(vis));
  memset(dis, 0, sizeof(dis));

  bfs(si, sj);
  cout << dis[0][3];
  return 0;
}