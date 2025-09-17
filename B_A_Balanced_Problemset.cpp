#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int mod = 1e9 + 7;

void solve()
{
    ll x, n;
    cin >> x >> n;
    ll s = x;
    for (ll i = 1; i*i<=x; i++)
    {
        if(x%i==0)
        {
            if(i>=n)
                s = min(s, i);
            if(x/i>=n)
                s = min(s, x / i);
        }
    }
    

    ll ans = x / s;
    cout << ans << endl;
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