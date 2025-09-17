#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    // ll n;
    // cin >> n;
    // vector<ll> a(n);
    ll w, h, a, b;
    cin >> w >> h >> a >> b;
    ll xa, ya, xb, yb, xc, yc, xd, yd;
    ll xa1, ya1, xb1, yb1, xc1, yc1, xd1, yd1;
    cin >> xa >> ya >> xa1 >> ya1;

    xb = xa + a, yb = ya;
    xc = xb, yc = yb + b;
    xd = xa, yd = ya + b;

    xb1 = xa1 + a, yb1 = ya1;
    xc1 = xb1, yc1 = yb1 + b;
    xd1 = xa1, yd1 = ya1 + b;

    if ((xa1 >= xa && xa1 <= xb) || (xb1 >= xa && xb1 <= xb) || (xa >= xa1 && xa <= xb1) || (xb >= xa1 && xb <= xb1))
    {
        ll gap;
        if(yd<yd1)
        {
            gap = ya1 - yd;
        }
        else{
            gap = ya - yd1;
        }
        if(gap%b==0)

            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else{
        ll gap;
        if(xc>xc1)
            gap = xd - xb1;
        else
            gap = xd1 - xb;

        if (gap % a == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
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