#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
  int u, v;
  long long c;
  Edge(int u, int v, long long c)
  {
    this->v = v;
    this->u = u;
    this->c = c;
  }
};

const int N = 1e5 + 5;
long long dis[N];

int main()
{

  int n, e;
  cin >> n >> e;
  vector<Edge> EdgeList;
  
  for (int i = 0; i < e; i++)
  {
    int u, v;
    long long c;
    cin >> u >> v >> c;
    EdgeList.push_back(Edge(u, v, c));
  }

  for (int i = 0; i < N; i++)
  {
    dis[i] = 1e18;
  }

  int src;
  cin >> src;
  dis[src] = 0;

  for (int i = 1; i <= n; i++)
  {
    for (Edge ed : EdgeList)
    {
      int u, v;
      long long c;
      u = ed.u;
      v = ed.v;
      c = ed.c;
      if (dis[u] != 1e18 && dis[u] + c < dis[v])
      {
        dis[v] = dis[u] + c;
      }
    }
  }

  bool cycle = false;
  for (Edge ed : EdgeList)
  {
    int u, v;
    long long c;
    u = ed.u;
    v = ed.v;
    c = ed.c;
    if (dis[u] != 1e18 && dis[u] + c < dis[v])
    {
      cycle = true;
      break;
    }
  }

  if (cycle)
  {
    cout << "Negative Cycle Detected" << endl;
  }
  else
  {
    int t;
    cin >> t;
    while (t--)
    {
      int des;
      cin >> des;

      if (dis[des] != 1e18)
      {
        cout << dis[des] << endl;
      }
      else
      {
        cout << "Not Possible" << endl;
      }
    }
  }

  return 0;
}