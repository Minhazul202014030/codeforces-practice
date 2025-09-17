#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
int mod = 1e9 + 7;

int f(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1 == 1)
        {
            ans = (ans * 1LL * a) % mod;
        }
        a = (a * 1LL * a) % mod;
        b = b >> 1;
    }
    return ans;
}

void solve()
{
    int x;
    cin >> x;
    vector<int> n, k;
    for (int i = 0; i < x; i++)
    {
        int a;
        cin >> a;
        n.push_back(a);
    }
    for (int i = 0; i < x; i++)
    {
        int a;
        cin >> a;
        k.push_back(a);
    }

    for (int i = 0; i < x; i++)
    {
        int ans = f(2, k[i]);
        // ans = ans % mod;
        cout << ans << endl;
    }
}

int main()
{
    FastIO;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
