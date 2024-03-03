#include <bits/stdc++.h>
using namespace std;

bool dp[100005];

void bottomUp()
{
    dp[1] = true;
    for (int i = 1; i <= 100000; i++)
    {
        if (dp[i])
        {
            if (i * 2 <= 100000)
                dp[i * 2] = true;
            if (i + 3 <= 100000)
                dp[i + 3] = true;
        }
    }
}

int main()
{

    memset(dp, false, sizeof(dp));
    bottomUp();

    int tt;
    cin >> tt;

    while (tt--)
    {
      
        int n;
        cin >> n;

        if (dp[n])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}