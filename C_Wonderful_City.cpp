#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;
#define INF 1000000000000000000LL

ll f(vector<vector<ll>> &a, vector<ll> &b)
{
    ll n = b.size();
    vector<bool> v1(n, false), v2(n, false), v3(n, false);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == a[i - 1][j] + 1)
                v1[i] = true; // TF not possible
            if (a[i][j] == a[i - 1][j])
                v2[i] = true; // FF, TT not possible

            if (a[i][j] + 1 == a[i - 1][j])
                v3[i] = true; // FT not possible
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (v1[i] && v2[i] && v3[i])
            return INF;
    }

    vector<ll> dp1(n), dp2(n);
    dp1[0] = 0;
    dp2[0] = b[0];
    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[0][0] = 0;
    dp[0][1] = b[0];

    for (int i = 1; i < n; i++)
    {
        if (v1[i] && v2[i]) // if TT, FF, TF not possible, then only FT possible
        {
            dp1[i] = INF;
            dp2[i] = dp1[i - 1]+b[i]; // FT possible
            dp[i][0] = INF;
            dp[i][1] = dp[i - 1][0] + b[i];
        }

        else if (v2[i] && v3[i]) // if TT, FF, FT not possible, then only TF possible
        {
            dp1[i] = dp2[i - 1]; // TF possible
            dp2[i] = INF;

            dp[i][0] = dp[i - 1][1];
            dp[i][1] = INF;
        }
        else if (v1[i] && v3[i]) // TF,FT not possible
        {
            // FF,TT possible
            dp1[i] = dp1[i - 1];
            dp2[i] = dp2[i - 1]+b[i];

            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1] + b[i];
        }
        else if (v1[i]) // TF not possible
        {
            // TT,FF,FT possible
            dp1[i] = dp1[i - 1];
            dp2[i] = min(dp1[i - 1], dp2[i - 1]) + b[i];

            dp[i][0] = dp[i - 1][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
        }
        else if(v2[i])// TT, FF not possible
        {
            //TF,FT possible
            dp1[i] = dp2[i - 1];
            dp2[i] = dp1[i - 1] + b[i];

            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + b[i];
        }
        else if(v3[i])// FT not possible
        {
            //TT,FF,TF possible
            dp1[i] = min(dp1[i - 1], dp2[i - 1]);
            dp2[i] = dp2[i - 1] + b[i];

            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][1] + b[i];
        }
        else{
            dp1[i] = min(dp1[i - 1], dp2[i - 1]);
            dp2[i] = min(dp1[i - 1], dp2[i - 1]) + b[i];

            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
        }
    }
    // return min(dp1[n - 1], dp2[n - 1]);

    return min(dp[n - 1][0], dp[n - 1][1]);
}

void solve()
{

    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n)), t(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    vector<ll> b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            t[i][j] = a[j][i];
        }
    }

    ll ans = f(a, b);
    if (ans >= INF)
    {
        cout << -1 << endl;
        return;
    }
    ans += f(t, c);
    if (ans >= INF)
    {
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
}

int main()
{
    fastIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}