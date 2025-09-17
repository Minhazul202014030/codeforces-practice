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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> a[i];
        
        if(a[i]<0)
            a[i] *= -1;
        // a.push_back(abs(x));
    }
    int m = a[0];
    sort(a.begin(), a.end());
    if(m>a[n/2])
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    // for(auto u:a)
        // cout << u << ' ';
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