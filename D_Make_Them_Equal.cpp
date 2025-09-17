#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int mod = 1e9 + 7;

unordered_map<int, int> mp;
int dp[1001];
int dis[1001];
// vector<int> dis(1001,0);
const int N = 1001;
// vector<int> d(N, N);
int d[N];

void precomp()
{
    // dp[1] = 0;
    // dp[2] = 1;
    // for (int i = 3; i <= 1000; i++)
    // {
    //     if (i % 2 == 1)
    //     {
    //         dp[i] = dp[i - 1] + 1;
    //     }
    //     else
    //     {
    //         dp[i] = dp[i / 2] + 1;
    //     }
    // }

    // queue<int> q;
    // q.push(1);
    // dis[1] = 0;
    // int vis[2001] = {0};
    // vis[1] = 1;

    // while (!q.empty())
    // {
    //     int a = q.front();
    //     q.pop();
    //     for (int i = a + 1; i <= a + (a / 2) && i <= 2000; i++)
    //     {
    //         if (!vis[i])
    //         {
    //             dis[i] = dis[a] + 1;
    //             q.push(i);
    //             vis[i] = 1;
    //         }
    //     }
    //     if (a + a <= 2000 && !vis[a + a])
    //     {
    //         dis[a + a] = dis[a] + 1;
    //         q.push(a + a);
    //         vis[a + a] = 1;
    //     }
    // }
    for (int i = 0; i < N; i++)
        d[i] = 1001;

    d[1] = 0;
    for (int i = 1; i < N; ++i)
    {
        for (int x = 1; x <= i; ++x)
        {
            int j = i + i / x;
            if (j < N)
                d[j] = min(d[j], d[i] + 1);
        }
    }

    // cout << d[1000] << endl;

    // cout << dis[1000];
}

int f(int i, int k, vector<int> &b, vector<int> &c, vector<vector<int>> &dpp)
{
    if (i < 0)
        return 0;

    if (dpp[i][k] != -1)
        return dpp[i][k];

    int nottake = f(i - 1, k, b, c, dpp);
    int take = 0;
    if (k >= d[b[i]])
    {
        take = c[i] + f(i - 1, k - d[b[i]], b, c, dpp);
    }
    return dpp[i][k] = max(nottake, take);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    int maxk = 0;
    for (int i = 0; i < n; i++)
    {
        maxk = max(maxk, d[b[i]]);
    }
    k = min(k, maxk * n);
    // vector<vector<int>> dpp(n + 1, vector<int>(k + 1, 0));
    int dpp[n + 1][k + 1];
    memset(dpp, 0, sizeof(dpp));
    // cout << f(n - 1, k, b, c, dpp) << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {

            // int nottake = 0;
            // if (i - 1 >= 0)
            int nottake = dpp[i - 1][j];
            int take = 0;
            if (j >= d[b[i - 1]])
            {
                take = c[i - 1] + dpp[i - 1][j - d[b[i - 1]]];
                // f(i - 1, j - d[b[i]], b, c, dpp);
            }
            dpp[i][j] = max(nottake, take);
        }
    }
    cout << dpp[n][k] << endl;

    // for (int i = 0; i <= n;i++)
    // {
    //     for (int j = 0; j <= k;j++)
    //     {
    //         cout << dpp[i][k] << ' ';
    //     }
    //     cout << endl;
    // }

    // cout << endl;
}

int main()
{
    FastIO;
    int t;
    cin >> t;
    precomp();
    while (t--)
    {
        solve();
    }

    return 0;
}