#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n" 
#define yes cout << "YES\n"
#define no cout << "NO\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    multiset<ll> st;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x%k);
    }
    // for(auto u:st)
    //     cout << u << ' ';

    // cout << endl;
    for (int i = 0; i < n; i++)
    {
        int x = a[i]%k;
        if(st.find(x)!=st.end()){
            st.erase(st.find(x));
        }
        else if (st.find(k-x)!=st.end())
        {

            st.erase(st.find(k - x));
        }
        else
        {
            no;
            return;
        }
    }
    yes;
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