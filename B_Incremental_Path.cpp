#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define f(x, y) for (ll i = x; i < y; i++)
#define ia(a, n) \
    f(i, n) cin >> a[i]
#define iv(v, n) \
    f(i, n) cin >> v[i]
#define endl "\n" 
#define yes cout << "YES\n"
#define no cout << "NO\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{
    ll n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<ll> st; 

    f(0,m){
        ll x;
        cin >> x;
        st.insert(x);
    }

    ll cur = 1;
    f(0,n){
        cur++;
        if(s[i]=='B'){
            while(st.count(cur))
                cur++;
        }
        st.insert(cur);
        if(s[i]=='B'){
            while (st.count(cur))
                cur++;
        }
    }

    cout << st.size() << endl;
    for(auto u:st)
        cout << u << ' ';

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