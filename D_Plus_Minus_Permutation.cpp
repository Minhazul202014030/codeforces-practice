#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int mod = 1e9 + 7;

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;

    ll l = (x * y) / __gcd(x, y);
    ll a = (n / x) - (n / l);
    ll b = (n / y) - (n / l);
    ll aa = (n * (n + 1)) / 2 - ((n - a) * (n - a + 1)) / 2;
    ll r = (n / y) - (n / l);
    ll bb = r * (r + 1) / 2;
    ll ans = aa - bb;
    cout << ans << endl;

    // cout << endl;
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