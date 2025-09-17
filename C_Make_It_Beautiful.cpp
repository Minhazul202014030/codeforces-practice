#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

ll p[64];

void solve()
{

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += __builtin_popcount(a[i]);
    }
    ll f[64] = {0};
    for (int i = 0; i < n; i++)
    {
        for (ll j = 0; j < 60; j++)
        {
            if ((a[i] & (1LL << j)) == 0)
                f[j]++;
        }
    }
    for (int i = 0; i < 60 && k > 0; i++)
    {
        ll lagbe = f[i];
        ll ase = k / p[i];
        ll rem = (ase - lagbe) * p[i];
        ans += min(lagbe, ase);
        k = max(0LL, rem);
    }

    cout << ans << endl;
}

int main()
{
    fastIO;
    int t;
    cin >> t;
    p[0] = 1;
    for (int i = 1; i < 60; i++)
    {
        p[i] = p[i - 1] * 2;
    }

    while (t--)
    {
        solve();
    }

    return 0;
}