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
    // vector<ll> a(n);
    if (n <= 2)
    {
        cout << 1 << endl;
        return;
    }
    ll lo=1, hi=n, ans = 0;
    while(lo<=hi)
    {
        ll mid = lo + (hi - lo) / 2;
        if(mid<=n/mid)
        {
            lo = mid + 1;
            ans = mid;
        }
        else
            hi = mid - 1;
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