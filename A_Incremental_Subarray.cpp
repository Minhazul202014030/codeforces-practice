#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    f(i, n) cin >> a[i]
#define iv(v, n) \
    f(i, n) cin >> v[i]
#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
typedef long long int ll;
const int MOD = 1000000007;

// vector<ll> v(n);
void solve()
{
    ll n, m;
    cin >> n >> m;
    ll a[m];
    ia(a, m);
    for (ll i = 1; i < m; i++)
    {
        if (a[i - 1] >= a[i])
        {
            cout << 1 << endl;
            return;
        }
    }

    cout << n - a[m - 1] + 1 << endl;
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