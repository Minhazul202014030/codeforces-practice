// #include <bits/stdc++.h>
// using namespace std;

// void test_case()
// {
//     int n;
//     cin >> n;

//     // Initialize operations and values arrays
//     vector<vector<string>> op(n + 1, vector<string>(2));
//     vector<vector<int>> val(n + 1, vector<int>(2));

//     // Read input
//     for (int i = 1; i <= n; i++)
//     {
//         string tmp1, tmp2, tmp3, tmp4;
//         cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
//         op[i][0] = tmp1;
//         op[i][1] = tmp3;
//         val[i][0] = stoi(tmp2);
//         val[i][1] = stoi(tmp4);
//     }

//     // Base case
//     // op[0] = {"+", "+"};
//     // val[0] = {1, 1};

//     vector<vector<long long>> dp(n + 2, vector<long long>(2, 0));
//     dp[n + 1][0] = dp[n + 1][1] = 1;

//     // Dynamic programming from n to 1 (reverse loop)
//     for (int i = n; i >= 1; i--)
//     {
//         dp[i][0] = (op[i][0] == "x")
//                        ? (dp[i + 1][0] + (val[i][0] - 1) * max(dp[i + 1][0], dp[i + 1][1]))
//                        : dp[i + 1][0];
//         dp[i][1] = (op[i][1] == "x")
//                        ? (dp[i + 1][1] + (val[i][1] - 1) * max(dp[i + 1][0], dp[i + 1][1]))
//                        : dp[i + 1][1];
//     }

//     long long ans = 0;

//     // Calculate answer
//     for (int i = 1; i <= n; i++)
//     {
//         long long sm = 0;
//         if (op[i][0] == "+")
//             sm += val[i][0];
//         if (op[i][1] == "+")
//             sm += val[i][1];
//         ans += sm * max(dp[i + 1][0], dp[i + 1][1]);
//     }

//     ans += dp[1][0];
//     ans += dp[1][1];

//     cout << ans << endl;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         test_case();
//     }
//     return 0;
// }

/*

#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);   // Stores the numerical values
    vector<pair<char, char>> v(n); // Stores the operation types

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> a[i].first >> v[i].second >> a[i].second;
    }

    vector<int> vec(n, 0); // Tracks which lane should dominate
    bool f = false;        // Flag to decide the dominating lane

    // Step 1: Traverse gates from end to start to determine dominance
    for (int i = n - 1; i >= 0; i--)
    {
        vec[i] = f;
        if (v[i].first == '+' && v[i].second == '+')
            continue;
        else if (v[i].first == '+')
            f = true;
        else if (v[i].second == '+')
            f = false;
        else if (a[i].first > a[i].second)
            f = false;
        else if (a[i].first < a[i].second)
            f = true;
    }
    // for (int i = 0; i < n - 1;i++)
    // {
    //     if (v[i+1].first == '+' && v[i+1].second == '+')
    //             continue;
    // }

        // Step 2: Forward computation to calculate the total people in each lane
        int l = 1, r = 1;
    for (int i = 0; i < n; i++)
    {
        int extra = 0;
        // Add or multiply for the left lane
        if (v[i].first == '+')
            extra += a[i].first;
        else
            extra += (a[i].first - 1) * l;

        // Add or multiply for the right lane
        if (v[i].second == '+')
            extra += a[i].second;
        else
            extra += (a[i].second - 1) * r;

        // Distribute the extra people based on dominance
        if (vec[i])
            r += extra;
        else
            l += extra;
    }

    // Final result
    cout << l + r << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        int n; // Number of gates
        cin >> n;

        vector<pair<pair<bool, long long>, pair<bool, long long>>> vec; // Stores operations and values
        vector<int> nxt(n, -1);                                         // Tracks dominance in subsequent gates

        // Input reading and initialization
        for (int i = 0; i < n; i++)
        {
            string op1, op2;
            long long val1, val2;
            cin >> op1 >> val1 >> op2 >> val2;

            if (op1 == "+" || op2 == "+")
            {
                if (op1 == "+" && op2 == "+")
                {
                    vec.push_back({{0, val1}, {0, val2}});
                }
                else if (op1 == "+")
                {
                    vec.push_back({{0, val1}, {1, val2}});
                    nxt[i] = 1; // Right dominates
                }
                else
                {
                    vec.push_back({{1, val1}, {0, val2}});
                    nxt[i] = 0; // Left dominates
                }
            }
            else
            {
                // Both operations are `x`
                if (val1 == val2)
                {
                    vec.push_back({{1, val1}, {1, val2}});
                }
                else if (val1 > val2)
                {
                    vec.push_back({{1, val1}, {1, val2}});
                    nxt[i] = 0; // Left dominates
                }
                else
                {
                    vec.push_back({{1, val1}, {1, val2}});
                    nxt[i] = 1; // Right dominates
                }
            }
        }

        // Backward pass to propagate dominance
        int prev = 0; // Start with no dominance
        for (int i = n - 1; i >= 0; i--)
        {
            if (nxt[i] == -1)
                nxt[i] = prev; // Inherit dominance from the next gate
            else
                prev = nxt[i];
        }

        long long left = 1, right = 1;

        // Forward computation to calculate final result
        for (int i = 0; i < n; i++)
        {
            long long temp = 0;

            // Calculate contribution from the left lane
            if (vec[i].first.first == 0)
            { // '+' operation
                temp += vec[i].first.second;
            }
            else
            { // 'x' operation
                temp += (vec[i].first.second - 1) * left;
            }

            // Calculate contribution from the right lane
            if (vec[i].second.first == 0)
            { // '+' operation
                temp += vec[i].second.second;
            }
            else
            { // 'x' operation
                temp += (vec[i].second.second - 1) * right;
            }

            // Distribute the result based on dominance
            if (i + 1 < n && nxt[i + 1])
            {
                right += temp; // Right lane dominates
            }
            else
            {
                left += temp; // Left lane dominates
            }
        }

        // Final result
        cout << left + right << "\n";
    }

    return 0;
}
