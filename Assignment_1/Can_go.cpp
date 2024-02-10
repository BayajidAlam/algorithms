#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[105][105];
bool vis[105][105];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#');
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj) && !vis[ci][cj])
        {
            dfs(ci, cj);
        }
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
        }
    }

    int ai, aj, bi, bj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'A')
            {
                ai = i;
                aj = j;
            }
            else if (a[i][j] == 'B')
            {
                bi = i;
                bj = j;
            }
        }
    }
    
    memset(vis, false, sizeof(vis));

    dfs(ai, aj);

    if (vis[bi][bj])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
