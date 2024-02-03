#include <bits/stdc++.h>
using namespace std;

//if just need to traversal we use dfs
const int N = 1e5 + 5;
vector<int> v[N];
bool vis[N];

void dfs(int src)
{
  cout << src << endl;
  vis[src] = true;
  // alternative of int i = 0; i < v[src].size(); i++ = int child : v[src]
  //visiting the children that are not visited yet
  for (int child : v[src])
  {
    if (vis[child] == false)
    {
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
    v[a].push_back(b);
    v[b].push_back(a);
  }

  // set default value of visit false
  memset(vis, false, sizeof(vis));

  // func 
  dfs(0);
  return 0;
}