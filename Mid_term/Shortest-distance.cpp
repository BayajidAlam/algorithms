#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e18

int main()
{

  ll n, e;
  cin >> n >> e;

  ll adj[n+1][n+1];
  
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
        adj[i][j] = 0;
      else
        adj[i][j] = INF;
    }
  }

  while (e--)
  {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    adj[a][b] = min(adj[a][b], c); 
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if ( adj[i][k] + adj[k][j] < adj[i][j])
        {
          adj[i][j] = adj[i][k] + adj[k][j];
        }
      }
    }
  }

  int q;
  cin >> q;
  while (q--)
  {
    int u, v;
    cin >> u >> v;
    if (adj[u][v] == INF)
      cout << -1 << endl;
    else
      cout << adj[u][v] << endl;
  }

  return 0;
}