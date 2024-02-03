#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
int level[1005];
bool visit[1005];

void bfs(int src)
{
  // initialize the queue and push the source node 
  queue<int> q;
  q.push(src);
  // make the visited element true 
  visit[src] = true;
  // set the level = 0
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
        // increment level 1 every time 
        level[child] = level[pr] + 1;
      }
    }
  }
}

int main()
{


  // input node and edges 
  int n, e;
  cin >> n >> e;
  while (e--)
  {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  // input src node 
  int src;
  cin >> src;

  // set visit and level default value false and -1 
  memset(visit, false, sizeof(visit));
  memset(level, -1, sizeof(level));

  bfs(src);

  // print the level of each node
  for (int i = 0; i < n; i++)
  {
    cout << i << " " << level[i] << endl;
  }
  return 0;
}