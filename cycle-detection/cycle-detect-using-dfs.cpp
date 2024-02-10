#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
// track visit
bool vis[N];
// vector of adj matrix
vector<int> adj[N];
// track parent
int parArray[N];
// is cycle detected though flag
bool flag;

void dfs(int parent)
{
  // cout << parent << endl;
  vis[parent] = true;
  for (int child : adj[parent])
  {
    if (vis[child] && child != parArray[parent])
    {
      flag = true;
    }
    if (!vis[child])
    {
      parArray[child] = parent;
      dfs(child);
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
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  // set def value
  memset(vis, false, sizeof(vis));
  memset(parArray, -1, sizeof(parArray));
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