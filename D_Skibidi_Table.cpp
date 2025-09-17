#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

ll p[61];

void f1(ll x, ll y, ll n)
{
    // ll r1 = 1, r2 = p[n], c1 = 1, c2 = p[n];
    ll sz = p[n];
    string s = "";
    while (sz > 1)
    {
        if (x > sz)
        {
            if (x % sz == 0)
                x = sz;
            else
                x = x % sz;
        }
        if (y > sz)
        {
            if (y % sz == 0)
                y = sz;
            else
                y = y % sz;
        }
        sz /= 2;
        if (x <= sz && y <= sz)
        {
            s = s + "00";
        }
        else if (x > sz && y > sz)
        {
            s = s + "01";
        }
        else if (x <= sz && y > sz)
        {
            s = s + "11";
        }
        else if (x > sz && y <= sz)
        {
            s = s + "10";
        }
    }
    ll m = s.length();
    ll d = 0;
    for (ll i = 0; i < m; i++)
    {
        if (s[i] == '1')
            d += p[m - 1 - i];
    }
    cout << d+1 << endl;
}
void f2(ll d, ll n)
{
    string s;
    d--;
    for (int i = 0; i < 2 * n; i++)
    {
        if (d & (1ll << i))
        {
            s += '1';
        }
        else
        {
            s += '0';
        }
    }

    reverse(s.begin(), s.end());
    // cout << s<<endl;

    // pair<ll, ll> r, l;
    ll r1 = 1, r2 = p[n], c1 = 1, c2 = p[n];
    for (int i = 0; i < 2 * n; i += 2)
    {
        if (s[i] == '0' && s[i + 1] == '0')
        {
            r2 = r2 / 2;
            c2 = c2 / 2;
        }
        else if (s[i] == '0' && s[i + 1] == '1')
        {
            r1 = r1 + ((abs(r1 - r2) + 1) / 2);
            c1 = c1 + ((abs(c1 - c2) + 1) / 2);
        }
        else if (s[i] == '1' && s[i + 1] == '0')
        {
            r1 = r1 + ((abs(r1 - r2) + 1) / 2);
            c2 = c2 / 2;
        }
        else if (s[i] == '1' && s[i + 1] == '1')
        {
            r2 = r2 / 2;
            c1 = c1 + ((abs(c1 - c2) + 1) / 2);
        }
    }

    cout << r1 << ' ' << c1 << endl;
}

void solve()
{

    ll n;
    cin >> n;
    // vector<ll> a(n);
    ll q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "->")
        {
            ll x, y;
            cin >> x >> y;
            f1(x, y, n);
        }
        else
        {
            ll d;
            cin >> d;
            f2(d, n);
        }
    }
}

int main()
{
    fastIO;
    int t;
    cin >> t;
    p[0] = 1;
    for (int i = 1; i <= 60; i++)
    {
        p[i] = p[i - 1] * 2;
    }

    while (t--)
    {
        solve();
    }

    return 0;
}