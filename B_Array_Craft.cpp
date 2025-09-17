#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int mod = 1e9 + 7;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ans(n + 1, 1);
    int id = y % 2;
    int id1 = x % 2;
    for (int i = 1; i <= n; i++)
    {
        if (i < y && i % 2 != id)
            ans[i] = -1;
        if (i > x && i % 2 != id1)
            ans[i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
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