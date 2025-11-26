#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n" 
#define yes cout << "YES\n"
#define no cout << "NO\n"
typedef long long int ll;
const int MOD = 1000000007;

vector<ll> v;
ll n, k, x;

bool ispossible(ll val, vector<ll> &a)
{

    set<ll> st;
    v.clear();
    for (int i = 1; i < n; i++)
    {
        if(a[i]-a[i-1]>=2*val){

            ll f = a[i - 1] + val;
            ll l = a[i] - val;
            ll t = f;
            while(t<=l && v.size()<k){
                if(st.find(t)==st.end())
                    v.push_back(t);
                st.insert(t);
                t++;
            }
        }
    }

    if(a[0]-val>=0){
        ll f = 0;
        ll l = a[0] - val;
        ll t = f;
        while (t <= l && v.size() < k)
        {
            if (st.find(t) == st.end())
                v.push_back(t);

            st.insert(t);
            t++;
        }
    }

    if(a[n-1]+val<=x){
        ll f = a[n - 1] + val;
        ll l = x;
        ll t = f;
        while (t <= l && v.size() < k)
        {
            if (st.find(t) == st.end())
                v.push_back(t);
            st.insert(t);
            t++;
        }
    }

    return v.size() >= k;
}

void solve()
{
    
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // for(auto &u:a)
    //     cin >> u;

    // cout << a.size();

    sort(a.begin(), a.end());
    ll l = 0, r = 1e9, ans = 0;

    while(l<=r){
        ll mid = (l + r) / 2;

        if(ispossible(mid,a)){
            l = mid + 1;
            ans = mid;
        }
        else{
            r = mid - 1;
        }
    }
    // cout << ans << endl;
    ispossible(ans,a);
    // if(ans==0){
    //     ispossible(0,a);
    // }
    for(auto u:v)
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