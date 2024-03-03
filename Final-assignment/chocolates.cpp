#include <bits/stdc++.h>
using namespace std;

int main()
{
  int tt;
  cin >> tt;
  while (tt--)
  {
    int n;
    cin >> n;
    int s = 0;
    int a[n];

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      s += a[i];
    }

    if (s % 2 != 0)
    {
      cout << "NO" << endl;
      continue;
    }

    int sum = s / 2;
    bool dp[n + 1][sum + 1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
      for (int j = 0; j <= sum; j++)
      {
        if (j < a[i - 1])
        {
          dp[i][j] = dp[i - 1][j];
        }
        else
        {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
        }
      }
    }
    if (dp[n][sum])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}