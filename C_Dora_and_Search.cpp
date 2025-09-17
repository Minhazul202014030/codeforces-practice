#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int l = 0, r = n - 1;
    int maxi = n;
    int mini = 1;
    while(l<=r)
    {
        int flag = 0;
        if(l<n && a[l]==mini){
            l++;
            mini++;
            flag = 1;
        }
        if(r>=0 && a[r]==mini){
            r--;
            mini++;
            flag = 1;
        }
        if (l < n && a[l] == maxi)
        {
            l++;
            maxi--;
            flag = 1;
        }
        if (r >= 0 && a[r] == maxi)
        {
            r--;
            maxi--;
            flag = 1;
        }
        if(flag==0){
            cout << l+1 << ' ' << r+1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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