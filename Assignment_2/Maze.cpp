#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1000][1000];
bool vis[1000][1000];
pair<int, int> par[1000][1000];
pair<int, int> start, dest;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#' && !vis[i][j];
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = cur.first + d[i].first;
            int cj = cur.second + d[i].second;

            if (valid(ci, cj))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                par[ci][cj] = cur;
            }
        }
    }
}

void print_grid()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'R')
            {
                start = {i, j};
            }
            else if (a[i][j] == 'D')
            {
                dest = {i, j};
            }
        }
    }

    memset(vis, false, sizeof(vis));

    bfs(start.first, start.second);

    if (!vis[dest.first][dest.second])
    {
        print_grid();
    }
    else
    {
        pair<int, int> cur = dest;
        while (cur != start)
        {
            if (a[cur.first][cur.second] != 'D')
            {
                a[cur.first][cur.second] = 'X';
            }
            cur = par[cur.first][cur.second];
        }

        print_grid();
    }

    return 0;
}        