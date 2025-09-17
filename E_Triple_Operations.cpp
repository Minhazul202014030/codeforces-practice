#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
vector<int> pre(200001, 0);
void solve()
{
    int l, r;
    cin >> l >> r;
    int ans;
    ans = (log(l) / log(3)) + 1;
    // int a = l;
    // int ans = 0;
    // while (a != 0)
    // {
    //     a = a / 3;
    //     ans++;
    // }
    ans = ans * 2;
    ans += (pre[r] - pre[l]);
    cout << ans;
    cout << endl;
}

int main()
{
    FastIO;
    int t;
    cin >> t;
    for (int i = 1; i < 200001; i++)
    {
        int ans = (log(i) / log(3));
        int a = i;
        // int ans = 0;
        // while (a != 0)
        // {
        //     a = a / 3;
        //     ans++;
        // }
        ans++;
        pre[i] = ans;
    }
    for (int i = 1; i < 200001; i++)
    {
        pre[i] += pre[i - 1];
    }

    while (t--)
    {
        solve();
    }

    return 0;
}