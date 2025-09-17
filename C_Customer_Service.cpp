#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;
    ll a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    
    vector<int> cnt;
    for (int i = 0; i < n; i++)
    {
        int cnt1 = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            if (a[i][j] == 1)
            {
                cnt1++;
            }
            else
                break;
        }
        cnt.push_back(cnt1);
    }

    sort(cnt.begin(), cnt.end());
    int sz = cnt.size();
    int ans = 0;
    for (int i = 0; i < sz; i++)
    {
        if (cnt[i] >= ans)
        {
            ans++;
        }
    }
    cout << ans << endl;

    // cout << endl;
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