#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n+5);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<int> dp(n + 5, 0),mx(n+5,-1e8);

    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], i + mx[v[i]]);
        mx[v[i]] = max(mx[v[i]], dp[i - 1] - (i - 1));
    }
    cout << dp[n];

    cout << endl;
}

int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
