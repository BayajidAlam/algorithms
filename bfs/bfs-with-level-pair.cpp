#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool visit[1005];

void bfs(int src,int des)
{
  queue<pair<int, int>> q;
  q.push({src, 0});
  visit[src] = true;

  while (!q.empty())
  {
    pair<int, int> p = q.front();
    q.pop();

    int pr = p.first;
    int level = p.second;

    if (level == des)
      cout << level << endl;

    for (int child : v[pr])
    {
      if (!visit[child])
      {
        q.push({child, level + 1});
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
  bfs(src, 3);

  return 0;
}