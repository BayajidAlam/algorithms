#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>> v[N];
// track the distance
int dis[N];

// the func
void dijkstra(int src)
{
  // push the pair to queue and add dis
  queue<pair<int, int>> q;
  q.push({src, 0});
  dis[src] = 0;

  while (!q.empty())
  {
    pair<int, int> parent = q.front();
    q.pop();
    int node = parent.first;
    int cost = parent.second;
    // for (int i = 0; i < v[node].size(); i++)
    // {

    // }

    // Alternative way
    for (pair<int, int> child : v[node])
    {
      int childNode = child.first;
      int childCost = child.second;
      if (cost + childCost < dis[childNode])
      {
        // path relax
        // update the new minimum dis
        dis[childNode] = cost + childCost;
        q.push({childNode, dis[childNode]});
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
    int a, b, c;
    cin >> a >> b >> c;
    // push value with cost
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }

  // set default value
  for (int i = 0; i < n; i++)
  {
    dis[i] = INT_MAX;
  }

  // dijkstra func
  dijkstra(0);

  // check
  for (int i = 0; i < n; i++)
  {
    cout << i << "-> " << dis[i] << endl;
  }
  return 0;
}