#include <iostream>
#include <vector>
#include <algorithm>

// Custom comparator for sorting based on the first column
bool compareFirstColumn(const std::vector<int> &a, const std::vector<int> &b)
{
    return a[0] < b[0];
}

int main()
{
    std::vector<std::vector<int>> vec = {
        {3, 2, 1},
        {1, 5, 4},
        {2, 8, 6}};

    // Sort the 2D vector using the custom comparator
    std::sort(vec.begin(), vec.end(), compareFirstColumn);

    // Print the sorted 2D vector
    for ( auto &row : vec)
    {
        // sort(row.begin(), row.end());
        for (int val : row)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
