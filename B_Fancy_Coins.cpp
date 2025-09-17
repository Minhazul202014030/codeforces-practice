#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

void solve()
{
    ll m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;

    ll ans = 0;
    ll fk_lagbe = max(m / k - ak, 0ll);
    ll f1_lagbe = max(m % k - a1, 0ll);
    ll total_f_lagbe = fk_lagbe + f1_lagbe;
    ll rem_a1 = max(a1 - (m % k), 0ll);
    total_f_lagbe -= rem_a1 / k;
    total_f_lagbe = max(total_f_lagbe, 0ll);
    cout << total_f_lagbe;
    cout << endl;
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

