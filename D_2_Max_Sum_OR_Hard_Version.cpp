#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
typedef long long int ll;
const int MOD = 1000000007;

string complement(string s)
{

    for (int i = 0; i <=30; i++)
    {
        if (s[i] == '0')
            s[i] = '1';
        else
            s[i] = '0';
    }

    return s;
}

void solve()
{
    ll l, r;
    cin >> l >> r;
    ll l1 = l, l2 = r, cnt = 0;

    map<string, ll> mp, vis;
    set<string> st;
    vector<string> vs;

    for (ll i = l; i <= r; i++)
    {
        string t = "";

        for (ll j = 0; j <= 30; j++)
        {
            if ((i & (1 << j)) == 0)
                t += '0';
            else
                t += '1';
        }
        reverse(t.begin(), t.end());
        vs.push_back(t);
        st.insert(t);
        mp[t] = i;
    }

    int sz = vs.size();
    ll n = r - l + 1;
    vector<ll> ans(n+ 1);
    for (ll i = sz - 1; i >= 0; i--)
    {
        string c = complement(vs[i]);
        if (st.find(c) != st.end() && vis[c] == 0)
        {
            ll x = mp[vs[i]];
            ll y = mp[c];
            ans[x] = y;
            vis[c] = 1;
        }
        else
        {
            ll j = 0;
            while (j <=30)
            {
                if (c[j] == '1')
                {
                    c[j] = '0';
                    if (st.find(c) != st.end() && vis[c] == 0)
                    {
                        int x = mp[vs[i]];
                        int y = mp[c];
                        ans[x] = y;
                        vis[c] = 1;

                        break;
                    }
                }
                j++;
            }
        }
    }

    ll sum = 0;
    for (ll i = 0; i <= n; i++)
    {
        sum += (i | ans[i]);
    }

    cout << sum << endl;
    for (auto u : ans)
    {
        cout << u << ' ';
    }
    cout << endl;
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