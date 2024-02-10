#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
// keep track of the visited node 
bool visit[1005];

void bfs(int src, int des)
{
  // saving the node and it's value of pair on vector
  queue<pair<int, int>> q;
  q.push({src, 0});
  visit[src] = true;

  bool flag = false;
  while (!q.empty())
  {
    //extract the front element form queue
    pair<int, int> p = q.front();
    q.pop();

    int pr = p.first;
    int level = p.second;

    if (level == des)
    {
      cout << level << endl;
      flag = true;
    }

    for (int child : v[pr])
    {
      // if child is not visited yet then increment the level
      if (!visit[child])
      {
        q.push({child, level + 1});
        visit[child] = true;
      }
    }
  }
  if (flag)
    cout << "Found" << endl;
  else
    cout << "NOT FOUND" << endl;
}

int main()
{
  // input node and edge 
  int n, e;
  cin >> n >> e;

  while (e--)
  {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  // input src and destination 
  int src, des;
  cin >> src >> des;

  // set default value of visited node false 
  memset(visit, false, sizeof(visit));
  
  bfs(src, des);

  return 0;
}