#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    int n, s;
    cin >> n >> s;
    vector<ll> a(n + 1), p(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    if (p[n] < s)
    {
        cout << -1 << endl;
        return;
    }
    int x = upper_bound(p.begin(), p.end(), s) - p.begin();
    int mn = n - (x - 1);
    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] == 0)
            continue;
        int x = upper_bound(p.begin(), p.end(), s + p[i - 1]) - p.begin();
        if (p[x - 1] < s + p[i - 1])
            break;
        mn = min(mn, n - (x - 1) + i - 1);
    }

    cout << mn << endl;
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