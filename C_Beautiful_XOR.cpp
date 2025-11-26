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

    ll a, b;
    cin >> a >> b;
    ll base1 = log2(a);
    ll base2 = log2(b);

    if (base2 > base1)
    {
        cout << -1 << endl;
        return;
    }
    vector<ll> ans;
    for (int i = 0; i < 32; i++)
    {
        ll t1 = ((1 << i) & a);
        ll t2 = ((1 << i) & b);
        if (t1 != t2)
        {
            if (t2 > 0)
                ans.push_back(t2);
            else
                ans.push_back(t1);
        }
    }

    cout << ans.size() << endl;
    for (auto u : ans)
    {
        cout << u << ' ';
    }
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