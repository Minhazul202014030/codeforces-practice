#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int mod = 1e9 + 7;

// void solve()
// {

//     ll x, y, a;
//     cin >> x >> y >> a;
//     // a += (1 / 2);
//     ll k = (a + x + y - 1) / (x + y);
//     ll z = k * (x + y);

//     // z = z - y;
//     // if()
//     if (z == a)
//         cout << "NO" << endl;
//     else if (z - y > a)
//         cout << "NO" << endl;
//     else
//         cout << "YES" << endl;
// }

void solve()
{
    ll x, y, a;
    cin >> x >> y >> a;
    ll l = 1;
    ll r = 1e9;
    ll k = 1;
    while (l <= r)
    {
    
        ll mid = l + (r - l) / 2;
        if ((mid * (x + y)) > a)
        {
            k = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    if(k*(x+y)==a)
        cout << "NO" << endl;
    else if (k * (x + y) > a)
    {
        int z = (k * (x + y)) - y;
        if (z > a)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    // cout << k << endl;
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