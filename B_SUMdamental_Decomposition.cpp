#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double knightProbability(int n, int k, int row, int column)
    {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, 0.0)));

        // Base case: The knight starts at (row, column) with probability 1
        dp[0][row][column] = 1.0;
        cout << 0 << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << dp[0][i][j] << ' ';
            }
            cout << endl;
        }
        // Possible knight moves
        vector<pair<int, int>> moves = {
            {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

        // Iterative DP transition
        for (int m = 1; m <= k; ++m)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    for (auto &move : moves)
                    {
                        int prev_i = i + move.first;
                        int prev_j = j + move.second;
                        if (prev_i >= 0 && prev_i < n && prev_j >= 0 && prev_j < n)
                        {
                            dp[m][i][j] += dp[m - 1][prev_i][prev_j] / 8.0;
                        }
                    }
                }
            }
            cout << m << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << dp[m][i][j] << ' ';
                }
                cout << endl;
            }
        }

        // Compute final probability sum
        double probability = 0.0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                probability += dp[k][i][j];
            }
        }

        return probability;
    }
};

int main()
{
    int n = 3, k = 2, row = 0, column = 0;
    Solution sol;
    cout << "Knight Probability: " << sol.knightProbability(n, k, row, column) << endl;
    return 0;
}
