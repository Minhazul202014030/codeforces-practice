#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    int n;
    cin >> n;
    // vector<ll> a(n);
    int a = sqrt(n);
    if (a * a == n)
    {
        if (a == 0)
            cout << 0 << ' ' << 0 << endl;
        else
            cout << 1 << ' ' << a - 1 << endl;
    }
    else
        cout << -1 << endl;
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