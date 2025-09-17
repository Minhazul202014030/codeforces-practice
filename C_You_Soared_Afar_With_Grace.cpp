#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int mod = 1e9 + 7;

void solve()
{
    unordered_map<string, vector<pair<string, double>>> mp;

    mp["a"].push_back({"vv", 1 / 2});
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> mp1, mp2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp1[a[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        mp2[b[i]] = i;
    }

    vector<int> s1, s2;
    for (int i = 0; i < n; i++)
    {
        int mid = (n + 1) / 2;
        if (i < mid)
            s1.push_back(a[i]);

        else
            s2.push_back(b[i]);
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (n % 2 == 1)
        s1.pop_back();
    // for (int i = 0; i < n / 2; i++)
    // {
    //     if (s1[i] != s2[i])
    //     {
    //         // cout << -1 << endl;
    //         // return;
    //     }
    // }
    vector<pair<int, int>> ans;
    int j = 0;

    // cout << mp1[5];
    for (int i = n - 1; i >=0; i--)
    {
        // int k = lower_bound(a.begin(), a.end(), b[i])-a.begin();

        if (a[j] != b[i])
        {
            int k = mp1[b[i]];
            int a1 = a[j];
            int a2 = a[k];
            int b1 = b[j];
            int b2 = b[k];
            swap(a[j], a[k]);
            swap(b[j], b[k]);
            mp1[a1] = k;
            mp1[a2] = j;
            mp2[b1] = k;
            mp2[b2] = j;

            ans.push_back({j, k});
        }
        j++;
    }
    j = n-1;
    for (int i = 0; i < n;i++)
    {
        if(a[i]!=b[j]){
            cout << -1 << endl;
            return;
        }
        j--;
    }
        cout << ans.size() << endl;
    for (auto u : ans)
    {
        cout << u.first + 1 << ' ' << u.second + 1 << endl;
    }
    // cout << mp1[5];

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
