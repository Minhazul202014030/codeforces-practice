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
    set<ll> st, st2;
    
    ll m = 5e5;
    for (ll i = 1; i * i <= n; i++)
    {
        if (i == 1)
            continue;
        st.insert(i * i);
    }
    for (ll i = 1; i  <= n; i++)
    {
        st2.insert(i);
    }
    ll p = (n * (n + 1)) / 2;
    for (ll i = 1; i * i <= p; i++)
    {
        if (i * i == p)
        {
            cout << "-1" << endl;
            return;
        }
    }

    cout << 2 << " " << 1 << " ";
    st2.erase(1);
    st2.erase(2);
    ll sum = 0;
    sum += 3;
    for (auto u : st)
    {
        cout << u - 1 << ' ' << u << ' ';
        st.insert(u - 1);
        st2.erase(u);
        st2.erase(u - 1);
        sum += (u + u - 1);
    }
    st.insert(1);
    st.insert(2);
    while(!st2.empty())
    {
        sum += *st2.begin();
        ll sq = sqrt(sum);
        if(sq*sq==sum)
        {
            sum -= *st2.begin();
            ll tmp = *st2.begin();
            st2.erase(tmp);
            sum += *st2.begin();
            cout << *st2.begin()<<' ';
            st2.erase(*st2.begin());
            st2.insert(tmp);
            
        }
        else
        {
            cout << *st2.begin() << ' ';
            st2.erase(*st2.begin());
        }
    }

    
    // for (ll i = 1; i <= n; i++)
    // {
    //     if (st.find(i) == st.end())
    //         cout << i << ' ';
    // }
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