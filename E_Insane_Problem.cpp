#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
int check(ll k, ll i, ll l1, ll l2, ll r1, ll r2)
{
    ll x = pow(k, i);
    ll tmpl = l1, tmpr = r1;
    ll ans = 0;
    while (l1 <= r1)
    {
        ll mid1 = l1 + (r1 - l1) / 2;
        // if (mid1 * x < l2)
        // {
        //     l1 = mid1 + 1;
        //     continue;
        // }
        if (mid1 * x <= r2)
        {
            ans = mid1;
            l1 = mid1 + 1;
        }
        else
        {
            r1 = mid1 - 1;
        }
    }
    return ans;
}

int check1(ll k, ll i, ll l1, ll l2, ll r1, ll r2)
{
    ll x = pow(k, i);
    ll tmpl = l1, tmpr = r1;
    ll ans = 1e9;
    while (l1 <= r1)
    {
        ll mid1 = l1 + (r1 - l1) / 2;
        // if (mid1 * x < l2)
        // {
        //     l1 = mid1 + 1;
        //     continue;
        // }
        if (mid1 * x < l2)
        {

            l1 = mid1 + 1;
        }
        else
        {
            ans = mid1;
            r1 = mid1 - 1;
        }
    }
    return ans;
}
void solve()
{
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll ans = 0;
    for (int i = 0; i < 32; i++)
    {
        ll x = pow(k, i);
        if (x > r2)
            break;
        ll r = check(k, i, l1, l2, r1, r2);
        ll l = check1(k, i, l1, l2, r1, r2);
        ll range = (r - l) + 1;
        if (range > 0)
            ans += range;
        // if (x > 0)
        //     ans += x;
    }

    cout << ans;
    cout << endl;
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