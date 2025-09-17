#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

bool canpass(ll st, vector<ll> &p, vector<ll> &d, ll n, ll k)
{
    map<pair<ll, ll>, ll> mp; // pos,0,cnt --->forward
                              // pos,1,cnt ----> backward
    if (st > p[n - 1])
        return true;

    ll i = lower_bound(p.begin(), p.end(), st) - p.begin();
    ll t = 0;
    ll dir = 0;
    if (p[i] != st)
    {
        if ((p[i] - st -d[i]) % k == 0)
        {
            mp[{p[i], dir}]++;
            dir = 1;
            // i--;
        }
        t += p[i] - st;
    }
    while (1)
    {
        if (dir == 0)// forward
        {

            if (i + 1 < n)
            {
                ll x = t + abs(p[i + 1] - p[i]) - d[i + 1];
                if (x % k == 0)
                {
                    mp[{p[i + 1], dir}]++;
                    if (mp[{p[i + 1], dir}] == 2)
                    {
                        return false;
                    }
                    dir = 1; // backward
                }
                t += abs(p[i + 1] - p[i]);
                i++;
            }
            else
            {
                ll x = max(0ll, t - d[n - 1]);
                if (x % k == 0)
                {
                    mp[{p[n - 1], dir}]++;
                    if (mp[{p[n - 1], dir}] == 2)
                    {
                        return false;
                    }
                    dir = 1;
                }
                else
                {
                    return true;
                }
            }
        }
        else if (dir == 1) // backward
        {
            if (i - 1 >= 0)
            {
                ll x = t + abs(p[i - 1] - p[i]) - d[i - 1];
                if (x % k == 0)
                {
                    mp[{p[i - 1], dir}]++;
                    if (mp[{p[i - 1], dir}] == 2)
                    {
                        return false;
                    }
                    dir = 0; // forward
                }
                t += abs(p[i - 1] - p[i]);
                i--;
            }
            else
            {
                ll x = max(0ll, t - d[0]);
                if (x % k == 0)
                {
                    mp[{p[0], dir}]++;
                    if (mp[{p[0], dir}] == 2)
                    {
                        return false;
                    }
                    dir = 0;
                }
                else
                {
                    return true;
                }
            }
        }
    }
}

void solve()
{

    ll n, k;
    cin >> n >> k;
    vector<ll> p(n), d(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll st;
        cin >> st;
        if (canpass(st, p, d, n, k))
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
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

