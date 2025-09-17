#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int r = 1, c = 1;
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '1')
            {
                r = 1;
                c = 1;
                int possible = 1;
                for (int k = 0; k < i; k++)
                {
                    if (a[k][j] == '0')
                    {
                        r = 0;
                        possible = 0;
                    }
                }
                for (int k = 0; k < j; k++)
                {
                    if (a[i][k] == '0')
                    {
                        c = 0;
                        possible =0;
                    }
                }
                if (possible==0)
                {
                    flag = 0;
                    break;
                }
            }
        }
    }

    if (flag == 1)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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