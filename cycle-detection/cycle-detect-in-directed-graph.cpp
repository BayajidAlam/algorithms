#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int vis[N];
bool pathVisit[N];
bool flag;

void dfs(int parent)
{
  vis[parent] = true;
  pathVisit[parent] = true;
  for (int child : adj[parent])
  {
    if (pathVisit[child])
    {
      flag = true;
    }
    if (!vis[child])
    {
      dfs(child);
    }
  }
  pathVisit[parent] = false;
}

int main()
{
  int n, e;
  cin >> n >> e;
  while (e--)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }

  memset(vis, false, sizeof(vis));
  memset(pathVisit, false, sizeof(pathVisit));
  flag = false;

  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      dfs(i);
    }
  }
  if (flag)
    cout << "Cycle" << endl;
  else
    cout << "No cycle" << endl;
  return 0;
}