#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    ll n, m;
    cin >> m >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int i = 0, j = n - 1, grp = 0;

    while (i <= j && grp < m)
    {
        for (int k = 0; k < 6; k++)
        {
            if (k % 2)
                cout << a[j] << " ";
            else
                cout << a[i] << " ";
        }
        cout << endl;
        grp++;

        if(grp<m)
        {
            for (int k = 0; k < 6; k++)
            {
                if (k % 2)
                    cout << a[i] << " ";
                else
                    cout << a[j] << " ";
            }
            cout << endl;
        }
        grp++;
        i++;
        j--;
    }
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