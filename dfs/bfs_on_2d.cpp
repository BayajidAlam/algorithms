#include <bits/stdc++.h>
using namespace std;

// num of row,col
int n, m;
// matrix that store elements
char a[20][20];
// keep track of visited node
int vis[20][20];
// keep track of distance
int dis[20][20];

// set up,down,left,right value
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

// check is i,j valid
bool valid(int i, int j)
{
  if (i < 0 || i >= n || j < 0 || j >= m)
    return false;
  else
    return true;
}

void bfs(int si, int sj)
{
  queue<pair<int, int>> q;
  // push the src, visited == true,dis = 0 initially
  q.push({si, sj});
  vis[si][sj] = true;
  dis[si][sj] = 0;

  while (!q.empty())
  {
    pair<int, int> par = q.front();
    // get the si, sj of parents
    int a = par.first;
    int b = par.second;
    q.pop();

    cout << par.first << " " << par.second << endl;

    for (int i = 0; i < 4; i++)
    {
      // get the i,j of children
      int ci = a + d[i].first;
      int cj = b + d[i].second;
      // check is ci,cj valid and visited = false
      if (valid(ci, cj) && vis[ci][cj] == false)
      {
        // if the ci,cj is valid and not visited yet
        // push to queue and track the visit and update the distance
        q.push({ci, cj});
        vis[ci][cj] = true;
        dis[ci][cj] = dis[a][b] + 1;
      }
    }
  }
}

int main()
{
  // input row,col
  cin >> n >> m;

  // input element of matrix
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  // input src i,j
  int si, sj;
  cin >> si >> sj;

  // def value of vis and dis
  memset(vis, false, sizeof(vis));
  memset(dis, -1, sizeof(dis));

  // execute func
  bfs(si, sj);

  return 0;
}