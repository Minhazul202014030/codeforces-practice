#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{
    ll n, rk, ck, rd, cd;
    cin >> n >> rk >> ck >> rd >> cd;

    ll ans = 0;

    if (rk > rd)
    {
        ans = max(ans, n - rd);
    }
    else if (rk < rd)
    {
        ans = max(ans, rd);
    }
    if (ck > cd)
    {
        ans = max(ans, n - cd);
    }
    else if (ck < cd)
    {
        ans = max(ans, cd);
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