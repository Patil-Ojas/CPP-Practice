#include <stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // normal approach double loop

    // then this approach
    stack<int> stck;
    vector<int> ans(n);
    stck.push(-1);

    for (int i=n-1; i>=0; i--)
    {
        int curr = arr[i];
        while (stck.top() >= curr)
            stck.pop();
        
        ans[i] = stck.top();
        stck.push(curr);
    }
    
    return ans;
}