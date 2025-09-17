#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Memoization table
vector<vector<int>> memo;

// Function to calculate the maximum score using recursion with memoization
int maxScoreRec(const vector<int> &nums, int i, int k, const vector<int> &prefixSum)
{
    if (k == 0)
        return 0; // No partitions left
    if (memo[i][k] != -1)
        return memo[i][k]; // Return memoized result

    int maxScore = 0;
    for (int j = i; j < nums.size(); ++j)
    {
        int sum = prefixSum[j + 1] - prefixSum[i];
        maxScore = max(maxScore, sum * (j - i + 1) + maxScoreRec(nums, j + 1, k - 1, prefixSum));
    }

    return memo[i][k] = maxScore;
}

int maxScorePartitionDP(const vector<int> &nums, int K)
{
    int N = nums.size();
    memo.assign(N + 1, vector<int>(K + 1, -1));
    vector<int> prefixSum(N + 1, 0);

    // Calculate prefix sums
    for (int i = 0; i < N; ++i)
    {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    return maxScoreRec(nums, 0, K, prefixSum);
}

int main()
{
    int N = 6, K = 2;
    vector<int> nums = {3, 1, 4, 1, 5, 9};
    cout << "Maximum score: " << maxScorePartitionDP(nums, K) << endl;
    return 0;
}
