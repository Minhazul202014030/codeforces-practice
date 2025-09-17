#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    ll n;
    cin >> n;
    vector<ll> a(n);
    ll fr[30] = {0};
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < 30; j++)
        {
            if (a[i] & (1 << j))
            {
                fr[j]++;
            }
        }
    }
    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
        ll sum = 0;
        for (ll j = 0; j < 30; j++)
        {
            if (a[i] & (1 << j))
            {
                sum = sum + ((n - fr[j]) * (1 << j));
            }
            else
            {
                sum = sum + (fr[j] * (1 << j));
            }
        }
        ans = max(ans, sum);
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