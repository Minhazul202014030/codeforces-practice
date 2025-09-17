// #include <iostream>
// #include <vector>
// #include <queue>
// #include <climits>

// using namespace std;

// const int MOD = 32768;

// vector<int> compute_min_operations()
// {
//     vector<int> dist(MOD, INT_MAX);
//     queue<int> q;

//     // Start from 0 which requires 0 operations
//     dist[0] = 0;
//     q.push(0);

//     while (!q.empty())
//     {
//         int current = q.front();
//         q.pop();

//         // Operation 1: Subtract 1 (reverse of adding 1)
//         int next = (current - 1 + MOD) % MOD;
//         if (dist[next] > dist[current] + 1)
//         {
//             dist[next] = dist[current] + 1;
//             q.push(next);
//         }

//         // Operation 2: Divide by 2 (reverse of multiplying by 2)
//         if (current % 2 == 0)
//         {
//             int next_div = current / 2;
//             if (dist[next_div] > dist[current] + 1)
//             {
//                 dist[next_div] = dist[current] + 1;
//                 q.push(next_div);
//             }

//             // Also consider adding MOD before dividing to handle overflow
//             int next_div_alt = (current + MOD) / 2;
//             if (next_div_alt != next_div && dist[next_div_alt] > dist[current] + 1)
//             {
//                 dist[next_div_alt] = dist[current] + 1;
//                 q.push(next_div_alt);
//             }
//         }
//     }

//     return dist;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // Precompute the minimum operations for all numbers
//     vector<int> min_ops = compute_min_operations();

//     int n;
//     cin >> n;

//     for (int i = 0; i < n; ++i)
//     {
//         int num;
//         cin >> num;
//         cout << min_ops[num] << " ";
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 32768;

void solve()
{

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] % MOD == 0)
            cout << 0 << ' ';
        else
        {
            int mn = 15;
            for (int j = 0; j <= 15; j++)
            {
                int c = a[i] + j;
                int op = j;
                while (c % MOD != 0)
                {
                    c = c * 2;
                    op++;
                }
                mn = min(mn, op);
            }
            cout << mn << ' ';
        }
    }
    cout << endl;
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