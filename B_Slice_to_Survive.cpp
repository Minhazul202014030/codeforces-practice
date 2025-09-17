#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

ll f(ll n)
{
    ll cnt = 0;
    while (n > 1)
    {
        n = (n + 1) / 2;
        cnt++;
    }
    return cnt;
}

void solve()
{

    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    // vector<ll> a(n);
    ll ans1 = 0, ans2 = 0;
    ll t1 = n, t2 = m;
    a = min(a, n - a + 1);
    b = min(b, m - b + 1);
    ans1 = f(n) + f(b);

    ans2 = f(m) + f(a);

    cout << min(ans1, ans2) + 1 << endl;
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