#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    int n;
    cin >> n;
    vector<int> a(n), ans;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ans.push_back(a[0]);
    int flag = 0;
    if (a[1] - a[0] > 0)
        flag = 1;
    for (int i = 1; i < n-1; i++)
    {
        if (a[i+1] - a[i] > 0 && flag==0)
        {
            ans.push_back(a[i]);
            flag = 1;
        }
        else if (a[i+1] - a[i] < 0 && flag==1){
            ans.push_back(a[i]);
            flag = 0;
        }
    }
    ans.push_back(a[n - 1]);
    cout << ans.size() << endl;
    for(auto u:ans)
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