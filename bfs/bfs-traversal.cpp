#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool visit[1005];

void bfs(int src)
{
  queue<int> q;
  q.push(src);
  visit[src] = true;
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
  int src;
  cin >> src;
  memset(visit, false, sizeof(visit));
  bfs(src);
  return 0;
}