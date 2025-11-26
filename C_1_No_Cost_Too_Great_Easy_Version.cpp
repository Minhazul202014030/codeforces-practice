#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
typedef long long int ll;
const int MOD = 1000000007;
const int N = 200001;

ll lp[N+1];

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
    for(auto u:a){
        ll t = u;
        set<ll> st;
        while(t>1){
            st.insert(lp[t]);
            t /= lp[t];
        }
        for (auto x : st)
        {
            fr[x]++;
        }
    }
    for(auto u:fr){
        if(u.second>1){
            cout << 0 << endl;
            return;
        }
    }
    for (auto u : a)
    {
        ll t = u+1;
        set<ll> st;
        while (t > 1)
        {
            st.insert(lp[t]);
            t /= lp[t];
        }
        for (auto x : st)
        {
            if(fr[x]){
                cout << 1 << endl;
                return;
            }
        }
    }
    cout << 2 << endl;
}

int main()
{
    fastIO;
    int t;
    cin >> t;
    for (int i = 2; i <= N; i++)
    {
        if(lp[i]==0){
            for (int j = 1; i * j <= N; j++){
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