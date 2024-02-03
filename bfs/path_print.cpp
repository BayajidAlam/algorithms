#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
// track's 
int level[1005];
bool visit[1005];
int par[1005];

void bfs(int src)
{

  queue<int> q;
  q.push(src);

  // set visit true and level 0;
  visit[src] = true;
  level[src] = 0;

  while (!q.empty())
  {

    int pr = q.front();
    q.pop();

    for (int child : v[pr])
    {
      if (!visit[child])
      {
        q.push(child);
        visit[child] = true;
        level[child] = level[pr] + 1;
        par[child] = pr;
      }
    }
  }
}

int main()
{

  //input node and edge
  int n, e;
  cin >> n >> e;

  while (e--)
  {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  //input src and destination
  int src, des;
  cin >> src >> des;

  // set default value 
  memset(visit, false, sizeof(visit));
  memset(level, -1, sizeof(level));
  memset(par, -1, sizeof(par));

  bfs(src);

  int x = des;
  //collect node come's to path
  vector<int> path;
  while (x != -1)
  {
    path.push_back(x);
    x = par[x];
  }

  //reverse the vector to find value in correct order
  reverse(path.begin(), path.end());

  //print the path
  for (int val : path)
  {
    cout << val << " ";
  }
  
  return 0;
}