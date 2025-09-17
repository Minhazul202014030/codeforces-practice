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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if(a[i]==a[i+1])
            {
                ll l = i * a[i];
                while (a[i] == a[i + 1] && i < n - 1)
                {
                    i++;
                }
                ll r = a[i] * (n - 1 - i);
                ans = min(ans, l + r);
            }
            else
                ans = min(ans, a[i] * (n - 1 - i));
        }
        if (i == n - 1)
        {
            ans = min(ans, a[i]*i);
        }
        else if (a[i] == a[i + 1])
        {
            ll l = i * a[i];
            while (a[i] == a[i + 1] && i < n - 1)
            {
                i++;
            }
            ll r = a[i] * (n - 1 - i);
            ans = min(ans, l + r);
        }
        else
        {
            ans = min(ans, (a[i] * i) + (a[i] * (n - 1 - i)));
        }
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