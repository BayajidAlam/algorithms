#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
int level[1005];
bool visit[1005];
int par[1005];

void bfs(int src)
{

  queue<int> q;
  q.push(src);

  visit[src] = true;
  level[src] = 0;

  while (!q.empty())
  {

    int pr = q.front();
    q.pop();

    for (int child : v[pr])
    {
      if (!visit[child])
      {
        q.push(child);
        visit[child] = true;
        level[child] = level[pr] + 1;
        par[child] = pr;
      }
    }
  }
}

int main()
{

  int n, e;
  cin >> n >> e;

  while (e--)
  {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  int src, des;
  cin >> src >> des;

  memset(visit, false, sizeof(visit));
  memset(level, -1, sizeof(level));
  memset(par, -1, sizeof(par));

  bfs(src);

  int x = des;
  vector<int> path;

  while (x != -1)
  {
    path.push_back(x);
    x = par[x];
  }

  reverse(path.begin(), path.end());
  for (int val : path)
  {
    cout << val << " ";
  }
  
  return 0;
}