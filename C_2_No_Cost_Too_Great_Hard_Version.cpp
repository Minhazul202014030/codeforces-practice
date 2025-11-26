#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n" 
#define yes cout << "YES\n"
#define no cout << "NO\n"
typedef long long int ll;
const int MOD = 1000000007;
const int N = 200001;

ll lp[N + 1];

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    map<ll, ll> fr;
    for (auto u : a)
    {
        ll t = u;
        set<ll> st;
        while (t > 1)
        {
            st.insert(lp[t]);
            t /= lp[t];
        }
        for (auto x : st)
        {
            fr[x]++;
        }
    }
    for (auto u : fr)
    {
        if (u.second > 1)
        {
            cout << 0 << endl;
            return;
        }
    }
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        ll t = a[i] + 1;
        set<ll> st;
        while (t > 1)
        {
            st.insert(lp[t]);
            t /= lp[t];
        }
        for (auto x : st)
        {
            if (fr.count(x))
            {
                ans = min(ans, b[i]);
            }
        }
    }

    auto it = min_element(b.begin(), b.end()) - b.begin();
    ll val = a[it];
    ll t = val;
    set<ll> st;
    while (t > 1)
    {
        st.insert(lp[t]);
        t /= lp[t];
    }
    for (auto x : st)
    {
        fr[x]--;
        if (!fr[x])
            fr.erase(x);    
    }
    for (auto [x, y] : fr){
        ans = min(ans, b[it]*(x - val % x));
    }

    sort(b.begin(),b.end());
    ans = min(ans, b[0] + b[1]);

    cout << ans << endl;
}

int main()
{
    fastIO;
    int t;
    cin >> t;
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            for (int j = 1; i * j <= N; j++)
            {
                lp[i * j] = i;
            }
        }
    }
    while (t--)
    {
        solve();
    }

    return 0;
}