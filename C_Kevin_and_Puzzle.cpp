// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;

// #define ll long long int
// #define pb push_back
// #define all(x) x.begin(), x.end()
// #define Max 10000000000000000

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T>
// using min_heap = priority_queue<T, vector<T>, greater<T>>;

// ll dp[200001], mod = 998244353;
// ll a[200001], n;

// ll solve(ll i)
// {
//     if (i == n)
//         return 1;
//     if (i == n - 1)
//     {
//         if (a[i] == a[i + 1])
//             return 2;
//         else
//             return 1;
//     }
//     if (dp[i] != -1)
//         return dp[i];
//     dp[i] = 0;
//     if (i < n && a[i + 1] == a[i]) // h h
//     {
//         dp[i] = (dp[i] + solve(i + 1)) % mod;
//     }
//     if (i < n - 1 && a[i + 2] - 1 == a[i]) // h L h if (i < n - 1 && a[i + 2] - 1 == a[i])
//     {
//         dp[i] = (dp[i] + solve(i + 2)) % mod;
//     }
//     return dp[i];
// }

// int main()
// {

//     ll t;
//     cin >> t;

//     while (t--)
//     {
//         cin >> n;

//         for (ll i = 0; i <= n; i++)
//         {
//             a[i] = 0;
//             dp[i] = -1;
//         }

//         for (ll i = 1; i <= n; i++)
//         {
//             cin >> a[i];
//         }
//         cout << solve(0) << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
// vector<vector<ll>> odp(200005, vector<ll>(2, 0));
ll mod = 998244353;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        // odp[a[i]][0] = 0;
        // odp[a[i]][1] = 0;
    }
    if (n == 1)
    {
        if (a[0] == 0)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
        return;
    }
    // vector<vector<ll>> odp(n + 1, vector<ll>(2, 0));
    map<pair<ll,ll>,ll> odp;
    if (a[0] == 0)
    {
        // odp[0][0] = 1;
        // odp[1][1] = 1;
        odp[{0, 0}] = 1;
        odp[{1, 1}] = 1;
    }
    else
    {
        odp[{1, 1}] = 1;
    }
    // vector<vector<ll>> dp(200005, vector<ll>(2, 0));
    // vector<vector<ll>> dpp(200005, vector<ll>(2, 0));
    for (int i = 1; i < n; i++)
    {
        // vector<vector<ll>> dp(200005, vector<ll>(2, 0));
        map<pair<ll, ll>, ll> dp;
        dp[{a[i], 0}] = (odp[{a[i], 0}] + odp[{a[i], 1}]) % mod;
        dp[{a[i - 1] + 1, 1}] = (odp[{a[i-1], 0}]) % mod;
        // cout << dp[a[i]][0] + dp[a[i - 1] + 1][1] << endl;
        odp = dp;
       
    }
    cout << (odp[{a[n - 1],0}] + odp[{a[n - 2] + 1,1}]) % mod << endl;
    // odp.clear();
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
