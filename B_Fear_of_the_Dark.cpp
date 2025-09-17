#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countUniqueXORTriplets(vector<int> &nums)
{
    unordered_set<int> uniqueXORValues;

    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            for (int k = j; k < n; ++k)
            {
                uniqueXORValues.insert(nums[i] ^ nums[j] ^ nums[k]);
            }
        }
    }

    return uniqueXORValues.size();
}

int main()
{
    vector<int> nums = {1,3}; // Example input
    cout << "Number of unique XOR triplet values: " << countUniqueXORTriplets(nums) << endl;
    return 0;
}