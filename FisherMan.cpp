// #include <bits/stdc++.h>
// using namespace std;
// #define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
// #define endl "\n"
// typedef long long int ll;

// int ans = INT_MAX;

// void f()
// {
//     vector<int> vis(n + 1, 0);
//     // 1
//     vis[p1] = 1;
//     int i = 1, t = p1;
//     t--;
//     int step = 1;
//     int left_ses = 0;
//     int right_ses = 0;
//     while (t >= 2)
//     {
//         int idx1 = p1 + i;
//         int idx2 = p1 - i;
//         if (idx1 < n + 1 && !vis[idx1])
//         {
//             vis[idx1] = 1;
//         }
//         else
//         {
//             right_ses = 1;
//             break;
//         }
//         if (idx2 > 0 && !vis[idx2])
//         {
//             vis[idx2] = 1;
//         }
//         else
//         {
//             left_ses = 1;
//             break;
//         }
//         i++;
//         t -= 2;
//         step += i * 2;
//     }
//     if(left_ses)
//     {
//         while(t>0)
//         {
//             step += i;
//             i++;
//             t--;
//         }
//     }
//     if(right_ses)
//     {

//     }
//     // 2

//     // 3
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     int g1, g2, g3;
//     cin >> g1 >> g2 >> g3;
//     int p1, p2, p3;
//     cin >> p1 >> p2 >> p3;

//     cout << endl;
// }

// int main()
// {
//     FastIO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int gate1Pos, gate2Pos, gate3Pos;

int abs(int a)
{
    return a < 0 ? -a : a;
}

int hashValue(int a, int b, int c)
{
    return a * 10000 + b * 100 + c;
}

vector<vector<int>> dp(12, vector<int>(1000005, -1));

int minCost(int pos, int fishers1, int fishers2, int fishers3)
{
    if (fishers1 < 0 || fishers2 < 0 || fishers3 < 0)
        return INT_MAX / 2;
    if (pos > n)
    {
        return (fishers1 == 0 && fishers2 == 0 && fishers3 == 0) ? 0 : INT_MAX / 2;
    }
    int hashIndex = hashValue(fishers1, fishers2, fishers3);
    if (dp[pos][hashIndex] != -1)
        return dp[pos][hashIndex];

    int takenFisher1 = 1 + abs(gate1Pos - pos) + minCost(pos + 1, fishers1 - 1, fishers2, fishers3);
    int takenFisher2 = 1 + abs(gate2Pos - pos) + minCost(pos + 1, fishers1, fishers2 - 1, fishers3);
    int takenFisher3 = 1 + abs(gate3Pos - pos) + minCost(pos + 1, fishers1, fishers2, fishers3 - 1);
    int noFisherTaken = minCost(pos + 1, fishers1, fishers2, fishers3);

    return dp[pos][hashIndex] = min(min(takenFisher1, takenFisher2), min(takenFisher3, noFisherTaken));
}
int main()
{
    cin >> n;
    int fishers1, fishers2, fishers3;
    cin >> gate1Pos >> gate2Pos >> gate3Pos;
    cin >> fishers1 >> fishers2 >> fishers3;

    cout << minCost(1, fishers1, fishers2, fishers3) << endl;
    return 0;
}