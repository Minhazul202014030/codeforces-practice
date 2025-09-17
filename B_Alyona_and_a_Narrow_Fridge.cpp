#include <iostream>
#include <cmath>

int leadingOneBitPosition(int num)
{
    return (num == 0) ? 0 : (int)log2(num) + 1;
}

int main()
{
    int num = 1e9; // 1000000000
    std::cout << "Leading 1 position: " << 64 - __builtin_clzll(num) << std::endl;

    return 0;
}
