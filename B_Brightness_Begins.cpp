#include <iostream>
#include <stack>
// #define mod 1000000007;

using namespace std;
 
// Recursive function to delete the middle element of a stack
void getMiddleElement(stack<int> &s, int currentIndex, int middleIndex)
{
    // Base case: If we have reached the middle element
    if (currentIndex == middleIndex)
    {
        cout << "Middle element is: " << s.top() << endl;
        return;
    }

    // Pop the top element
    int topElement = s.top();
    s.pop();

    // Recursive call to reach the middle element
    getMiddleElement(s, currentIndex + 1, middleIndex);

    // Push the element back after the recursive call
    s.push(topElement);
    return;
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5); // Stack: [1, 2, 3, 4, 5] (5 is at the top)

    int size = s.size();
    int middleIndex = size / 2; // Calculate middle index (0-based)

    getMiddleElement(s, 0, middleIndex);
    while (!s.empty())
    {
        cout << s.top() << "\n";
        s.pop();
    }

    return 0;
}
