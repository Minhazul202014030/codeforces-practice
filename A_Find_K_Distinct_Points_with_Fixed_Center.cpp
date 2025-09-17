#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

void solve()
{
    ll x, y, k;
    cin >> x >> y >> k;
    vector<ll> a, b;
    ll sum = 0, cnt = 0;
    ll i = 1;
    while (cnt < k / 2)
    {
        // a.push_back(i);
        // b.push_back(i);
        cout << x + i << " " << y + i << endl;

        i++;
        cnt++;
    }
    cnt = 0;
    i = 1;
    while (cnt < k / 2)
    {
        // a.push_back(i);
        // b.push_back(i);
        cout << x - i << " " << y - i << endl;

        i++;
        cnt++;
    }
    if(k%2)
        cout << x << " " << y<<endl;

    // cout << endl;
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
