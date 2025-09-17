#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    int n, m;
    cin >> n >> m;
    // vector<ll> a(n);
    int f[n + 1];
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    // // cout << f[5] << endl;
    // for (auto u : f)
    //     cout << u << ' ';
    while (m--)
    {
        int l, w, h;
        cin >> l >> w >> h;
        if (h >= f[n] && (f[n - 1] + f[n]) <= l && f[n] <= w)
        {
            cout << 1;
        }
        else if (h >= f[n] && (f[n - 1] + f[n]) <= w && f[n] <= l)
        {
            cout << 1;
        }
        else if (h >= (f[n - 1] + f[n]) && f[n] <= l && f[n] <= w)
        {
            cout << 1;
        }
        else
            cout << 0;
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