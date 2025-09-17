#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

// ll dp[200001][10]={0};
ll mod = 1e9 + 7;

// void precompute()
// {
//     // for (int i = 0; i < 200001; i++)
//     // {
//     //     for (int j = 0; j < 10; j++)
//     //     {
//     //         dp[i][j] = 0;
//     //     }
//     // }

//     for (int j = 0; j < 10; j++)
//     {
//         dp[0][j] = 1;
//     }
//     for (int k = 1; k < 200001; k++)
//     {
//         for (int digit = 0; digit < 10; digit++)
//         {
//             // dp[i][j] = -1;
//             if (digit <= 8)
//             {
//                 dp[k][digit] = dp[k - 1][digit + 1];
//             }
//             else
//             {
//                 dp[k][digit] = (dp[k - 1][1] + dp[k - 1][0]) % mod;
//             }
//         }
//     }
// }

void solve()
{
    int m;
    string n;
    cin >> n;
    cin >> m;
    int sz = n.length();

    ll dp[m + 1][10] = {0};

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         dp[i][j] = 0;
    //     }
    // }

    for (int j = 0; j < 10; j++)
    {
        dp[0][j] = 1;
    }
    for (int k = 1; k <= m; k++)
    {
        for (int digit = 0; digit < 10; digit++)
        {
            // dp[i][j] = -1;
            if (digit <= 8)
            {
                dp[k][digit] = dp[k - 1][digit + 1];
            }
            else
            {
                dp[k][digit] = (dp[k - 1][1] + dp[k - 1][0]) % mod;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < sz; i++)
    {
        int dig = n[i] - '0';
        ans = (ans + dp[m][dig]) % mod;
    }
    cout << ans << endl;
}

int main()
{
    FastIO;
    int t;
    cin >> t;
    // precompute();
    while (t--)
    {
        solve();
    }

    return 0;
}