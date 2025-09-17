#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    int n, m;
    cin >> n >> m;
    // vector<ll> a(n);
    char c[n][m];
    // vector<vector<char>> c(n, vector<char>(m));
    vector<vector<int>> a(n, vector<int>(m, 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == '-')
                a[i][j] = 0;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }

    int aa, bb, x, y;
    cin >> aa >> bb >> x >> y;
    if (a[aa - 1][bb - 1] == 0 || a[x - 1][y - 1] == 0)
    {
        cout << -1 << endl;
        return;
    }
    int dx[] = {-1, 0, +1, 0};
    int dy[] = {0, +1, 0, -1};
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    q.push({{aa - 1, bb - 1}, 0});
    vis[aa - 1][bb - 1] = 1;
    while (!q.empty())
    {
        int cur_i = q.front().first.first;
        int cur_j = q.front().first.second;
        int dis = q.front().second;
        q.pop();
        if (cur_i == x - 1 && cur_j == y - 1)
        {
            cout << dis << endl;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nex_i = cur_i + dx[i];
            int nex_j = cur_j + dy[i];

            if (nex_i >= 0 && nex_i < n && nex_j >= 0 && nex_j < m && !vis[nex_i][nex_j] && a[nex_i][nex_j] == 1)
            {
                vis[nex_i][nex_j] = 1;
                q.push({{nex_i, nex_j}, dis + 1});
            }
        }
    }
    cout << -1 << endl;
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