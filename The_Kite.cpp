#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    ll n;
    cin >> n;
    // vector<char> a(2*n+5);
    char ch[(2 * n) + 5][(2 * n) + 5];
    int x = (2 * n) + 5;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            ch[i][j] = ' ';
        }
    }
    int i = 1;
    for (int j = n; j >= 1; j--)
    {
        ch[i][j] = '/';

        for (int k = j + 1; k <= n; k++)
        {
            ch[i][k] = '-';
        }
        i++;
    }
    i = 1;
    for (int j = n + 1; j <= 2 * n; j++)
    {
        ch[i][j] = '\\';

        for (int k = j - 1; k > n; k--)
        {
            ch[i][k] = '-';
        }
        i++;
    }

    i = n + 1;
    for (int j = 1; j <= n; j++)
    {
        ch[i][j] = '\\';
        for (int k = j + 1; k <= n; k++)
        {
            ch[i][k] = '-';
        }
        i++;
    }
    i = n + 1;
    for (int j = 2 * n; j >= n; j--)
    {
        ch[i][j] = '/';
        for (int k = j - 1; k > n; k--)
        {
            ch[i][k] = '-';
        }
        i++;
    }

    for (i = 1; i <= 2 * n; i++)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            cout << ch[i][j];
        }
        cout << endl;
    }
}

int main()
{
    fastIO;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
