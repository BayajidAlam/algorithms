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
    parent[i] = -1;
    grp_size[i] = 1;
  }
}

int dsu_find(int node)
{
  if (parent[node] == -1)
    return node;
  int leader = dsu_find(parent[node]);
  parent[node] = leader;
  return leader;
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

  int min_cost = 0;
  int removed_roads = 0;

  for (Edge ed : Edgelist)
  {
    int leaderU = dsu_find(ed.u);
    int leaderV = dsu_find(ed.v);

    if (leaderU == leaderV)
    {
      removed_roads++;
      continue;
    }
    else
    {
      dsu_union_by_size(ed.u, ed.v);
      min_cost += ed.w;
    }
  }

  if (grp_size[dsu_find(1)] == n) 
    cout << removed_roads << " " << min_cost << endl;
  else
    cout << "Not Possible" << endl;

  return 0;
}