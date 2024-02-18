#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int grp_size[N];

class Edge
{
public:
  int u, v, w;
  Edge(int u, int v, int w)
  {
    this->u = u;
    this->v = v;
    this->w = w;
  }
};

bool cmp(Edge a, Edge b)
{
  return a.w < b.w;
}

void dsu_initialize(int n)
{
  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
    grp_size[i] = 1;
  }
}

int dsu_find(int node)
{
  if (parent[node] == node)
    return node;
  return parent[node] = dsu_find(parent[node]);
}

void dsu_union_by_size(int node1, int node2)
{
  int leaderA = dsu_find(node1);
  int leaderB = dsu_find(node2);

  if (grp_size[leaderA] > grp_size[leaderB])
  {
    parent[leaderB] = leaderA;
    grp_size[leaderA] += grp_size[leaderB];
  }
  else
  {
    parent[leaderA] = leaderB;
    grp_size[leaderB] += grp_size[leaderA];
  }
}

int main()
{
  int n, e;
  cin >> n >> e;

  dsu_initialize(n);
  vector<Edge> Edgelist;

  while (e--)
  {
    int u, v, w;
    cin >> u >> v >> w;
    Edgelist.push_back(Edge(u, v, w));
  }

  sort(Edgelist.begin(), Edgelist.end(), cmp);
  long long minimumCost = 0;
  int connectedLines = n;

  for (Edge ed : Edgelist)
  {
    int leaderU = dsu_find(ed.u);
    int leaderV = dsu_find(ed.v);

    if (leaderU != leaderV)
    {
      dsu_union_by_size(ed.u, ed.v);
      minimumCost += ed.w;
      connectedLines--;
    }
  }

  if (connectedLines > 1)
    cout << -1 << endl;
  else
    cout << minimumCost << endl;
  return 0;
}