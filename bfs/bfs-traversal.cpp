#include <bits/stdc++.h>
using namespace std;

// global vector that store all the connected node
vector<int> v[100000];
// keep track of visited node
bool vis[10000];

void bfs(int src)
{
  queue<int> q;
  // push the src to queue and track the visit
  q.push(src);
  vis[src] = true;

  while (!q.empty())
  {
    int pr = q.front();
    q.pop();
    cout << pr << endl;

    // find the connected node with src
    // for (int i = 0; i < v[pr].size(); i++)
    // {
    //   int child = v[pr][i];
    //   cout << child << " ";
    // }

    // alternative way
    for (int child : v[pr])
    {
      // if child is not visited yet then, push to queue and track the visit
      if (!vis[child])
      {
        q.push(child);
        vis[child] = true;
      }
    }
  }
}

int main()
{

  // initialize node and edge
  int n, e;
  cin >> n >> e;
  while (e--)
  {
    // input vertices
    int a, b;
    cin >> a >> b;

    // if undirected push push both a and b to corresponding vector index
    v[a].push_back(b);
    v[b].push_back(a);
  }

  // input src
  int src;
  cin >> src;

  // full the vis with false as element
  memset(vis, false, sizeof(vis));

  // call the func
  bfs(src);
  return 0;
}