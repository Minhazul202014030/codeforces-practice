#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1e9 + 7;

// Function to check if a number is a palindrome
bool isPalindrome(int x)
{
    std::string s = std::to_string(x);
    std::string rev_s = s;
    std::reverse(rev_s.begin(), rev_s.end());
    return s == rev_s;
}

int main()
{
    int t;
    std::cin >> t;
    std::vector<int> palindromes;

    // Generate all palindromic numbers up to 40000 (maximum value of n)
    for (int i = 1; i <= 40000; ++i)
    {
        if (isPalindrome(i))
        {
            palindromes.push_back(i);
        }
    }
    std::vector<int> dp(40004 + 1, 0);
    dp[0] = 1;

    for (int pal : palindromes)
    {
        for (int i = pal; i <= 40004; ++i)
        {
            dp[i] = (dp[i] + dp[i - pal]) % MOD;
        }
    }

    while (t--)
    {
        int n;
        std::cin >> n;
        

        std::cout << dp[n] << std::endl;
    }

    return 0;
}
