#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> v,v1;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        mp[x]++;
    }
    
    int cnt = 0;
    for(auto u: mp)
    {
        cnt = max(cnt, u.second);
    }
    int ans = n - cnt;
    // for (int i = m+1; i < n; i++)
    // {
    //     if (v[i] < v[m])
    //         cnt++;
    // }
    cout << ans << endl;
}

int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
