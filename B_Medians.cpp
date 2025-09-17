#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

int f(int i, vector<int> &v, vector<int> &psum, int k, vector<vector<int>> &dp)
{
    int n = v.size();
    
    if(k==0)
        return 0;

    if(dp[i][k]!=-1)
        return dp[i][k];

    int ans = INT_MIN;

    for (int j = i; j < n; j++)
    {
        int sum = psum[j + 1] - psum[i];
        int len = j + 1 - i;
        int m = (sum * len)+f(j+1,v,psum,k-1,dp);
        ans = max(ans, m);
        // cout << ans << " ";
    }

    return dp[i][k]= ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v,psum(n+1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        psum[i + 1] = psum[i] + v[i];
        // cout << psum[i + 1]<<" ";
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    cout << f(0, v,psum, k,dp) << endl;
    
}

int main()
{
    FastIO;
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // Function to calculate the maximum score using partition DP
// int maxScorePartitionDP(const vector<int> &nums, int K)
// {
//     int N = nums.size();
//     vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
//     vector<int> prefixSum(N + 1, 0);

//     // Calculate prefix sums
//     for (int i = 0; i < N; ++i)
//     {
//         prefixSum[i + 1] = prefixSum[i] + nums[i];
//     }

//     // Fill the DP table
//     for (int k = 1; k <= K; ++k)
//     {
//         for (int i = k; i <= N; ++i)
//         {
//             for (int j = k - 1; j < i; ++j)
//             {
//                 int sum = prefixSum[i] - prefixSum[j];
//                 dp[i][k] = max(dp[i][k], dp[j][k - 1] + sum * (i - j));
//             }
//         }
//     }

//     return dp[N][K];
// }

// int main()
// {
//     // int N = 6, K = 2;
//     // vector<int> nums = {3, 1, 4, 1, 5, 9};
//     int n, k;
//         cin >> n >> k;
//         vector<int> v,psum(n+1);
//         for (int i = 0; i < n; i++)
//         {
//             int x;
//             cin >> x;
//             v.push_back(x);
//         }
//     cout << "Maximum score: " << maxScorePartitionDP(v, k) << endl;
//     return 0;
// }
