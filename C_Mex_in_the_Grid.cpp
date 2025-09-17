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
    vector<vector<ll>> a(n, vector<ll>(n,-1));
    // int a[n][n];
    int cnt = (n * n) - 1;
    int i = n , j = -1;
    while (1)
    {
        if(cnt<0)
            break;
        // right
        i--;
        j++;
        while (j < n && a[i][j] == -1 && cnt >= 0)
        {
            a[i][j] = cnt;
            j++;
            cnt--;
        }

        // up
        j--;
        i--;
        while (i >= 0 && a[i][j] == -1 && cnt>=0)
        {
            a[i][j] = cnt;
            i--;
            cnt--;
        }
        // left
        i++;
        j--;
        // j = n-1;
        // i = 0;
        while (j >= 0 && a[i][j] == -1 && cnt >= 0)
        {
            a[i][j] = cnt;
            j--;
            cnt--;
        }

        // down
        // i = 0;
        // j = 0;
        j++;
        i++;
        while (i < n - 1 && a[i][j] == -1 && cnt >= 0)
        {
            a[i][j] = cnt;
            cnt--;
            i++;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
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