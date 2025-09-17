#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int minStepsToZero(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        string number = to_string(i);
        for (char digit : number)
        {
            int d = digit - '0';
            if (i - d >= 0)
            {
                dp[i] = min(dp[i], dp[i - d] + 1);
            }
        }
    }

    return dp[n];
}

int main()
{
    int n;
    // cout << "Enter a number: ";
    cin >> n;
    cout << "Minimum steps to reduce " << n << " to 0: " << minStepsToZero(n) << endl;
    return 0;
}
