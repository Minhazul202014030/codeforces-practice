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
    vector<ll> v(n);
    int flag = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int cnt = 0;
    ll p = -1;
    for (int i = 1; i < n; i++)
    {
        if (i >= 3 && v[i] == v[i - 1] && v[i - 1] == v[i - 2] && v[i - 2] == v[i - 3])
        {
            cout << "Yes" << endl;
            return;
        }
        if (v[i] == v[i - 1] && p != v[i])
        {
            cnt++;
            if (cnt >= 2)
            {
                cout << "Yes" << endl;
                return;
            }
            p = v[i];
        }

        if (v[i] - v[i - 1] == 1)
            continue;
        else if (v[i] - v[i - 1] > 1)
            cnt = 0;
    }

    cout << "No" << endl;
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