#include <bits/stdc++.h> 

void solve3000(stack<int> &stck, int x, int &n)
{
    if (n==0)
    {
        stck.push(x);
        return ;
    }

    int temp = stck.top();
    stck.pop();
    n--;
    solve3000(stck, x, n);
    stck.push(temp);
    return ;
}   

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    int n = myStack.size();

    solve3000(myStack, x, n);
    return myStack;
}
