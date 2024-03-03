#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool subset_sum(int n, int a[], int s)
{
  if (s == 0)
    return true;
  if (n == 0 || s < 0)
    return false;
  if (dp[n][s] != -1)
    return dp[n][s];
  bool opt1 = subset_sum(n - 1, a, s - a[n - 1]);
  bool opt2 = subset_sum(n - 1, a, s);
  return dp[n][s] = opt1 || opt2;
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {

    int n, m;
    cin >> n >> m;
    int a[n];

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    int s = 1000 - m;
    memset(dp, -1, sizeof(dp));
    
    if (subset_sum(n, a, s))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}