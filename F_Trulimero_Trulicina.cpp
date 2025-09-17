#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int a[n][m];
    if(n%k==0 && m%k==0)
    {
        // first row
        int val = 1;
        for (int i = 0; i < m;i++)
        {
            a[0][i] = val;
            val++;
            if(val>k)
                val = 1;
        }
        for (int i = 0; i < m;i++)
        {
            int val = a[0][i];
            for (int j = 1; j < n; j++)
            {
                val++;
                if (val>k)
                    val = 1;
                a[j][i] = val;
            }
        }
    }
    else if(n%k==0)// row wise
    {
        int val = 1;
        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = val;
                val++;
                if(val>k)
                    val = 1;
            }
            
        }
    }
    else if(m%k==0)// col wise
    {
        int val = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[j][i] = val;
                val++;
                if(val>k)
                    val = 1;
            }
            
        }
        
    }
    else{
        // cout << "serially" << endl;
        int val = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = val;
                val++;
                if (val>k)
                    val = 1;
            }
            
        }      
    }
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m; j++){
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