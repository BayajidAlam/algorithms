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

// bfs func
void bfs(int s)
{
  queue<int> q;
  q.push(s);
  vis[s] = true;
  while (!q.empty())
  {
    int pr = q.front();
    cout << pr << endl;
    q.pop();
    for (int child : adj[pr])
    {
      if (vis[child] && parArray[pr] != child)
      {
        flag = true;
      }
      if (!vis[child])
      {
        vis[child] = true;
        parArray[child] = pr;
        q.push(child);
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
      bfs(i);
    }
  }

  if (flag)
    cout << "Cycle" << endl;
  else
    cout << "No cycle" << endl;
  return 0;
}