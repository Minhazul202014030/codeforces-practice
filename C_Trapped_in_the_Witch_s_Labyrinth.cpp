
#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

map<pair<int, int>, int> status;

bool dfs(int i, int j, vector<vector<char>> &c, vector<vector<int>> &vis, int n, int m)
{
    if (i >= n || i < 0 || j >= m || j < 0)
    {
        return true;
    }
    if (vis[i][j] == 1)
    {
        if (status[{i, j}] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if (c[i][j] == '?')
    {
        return false;
    }
    bool issuccess;
    if (c[i][j] == 'U' && vis[i][j] == 0)
    {
        vis[i][j] = 1;
        issuccess = dfs(i - 1, j, c, vis, n, m);
    }
    if (c[i][j] == 'D' && vis[i][j] == 0)
    {
        vis[i][j] = 1;
        issuccess = dfs(i + 1, j, c, vis, n, m);
    }
    if (c[i][j] == 'L' && vis[i][j] == 0)
    {
        vis[i][j] = 1;
        issuccess = dfs(i, j - 1, c, vis, n, m);
    }
    if (c[i][j] == 'R' && vis[i][j] == 0)
    {
        vis[i][j] = 1;
        issuccess = dfs(i, j + 1, c, vis, n, m);
    }
    if (issuccess)
    {
        status[{i, j}] = 1;
        return true;
    }
    else
    {
        status[{i, j}] = 0;
        return false;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    // char c[n][m];
    vector<vector<char>> c(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
        }
    }
    int flag = 0;
    for (int i = 0; i < m; i++)
    {
        if (c[0][i] != '?')
            flag = 1;
        if (c[n - 1][i] != '?')
            flag = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (c[i][0] != '?')
            flag = 1;
        if (c[i][m - 1] != '?')
            flag = 1;
    }
    if (flag == 0)
    {
        cout << n * m << endl;
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (c[i][j] != '?')
                {

                    int r = dfs(i, j, c, vis, n, m);
                    if (r == false)
                    {
                        ans++;
                    }

                    // if (dfs() == true)
                    // {
                    // }
                }
                // else
                //     ans++;
            }
        }
    }
    cout << ans;
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