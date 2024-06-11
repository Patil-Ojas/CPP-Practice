#include <bits/stdc++.h> 

void solve3000(stack<int>&stck, int mid, int &count)
{
    if (count==mid)
    {
        stck.pop();
        return ;
    }
    int temp = stck.top();
    stck.pop();
    ++count;
    solve3000(stck, mid, count);
    stck.push(temp);
    return ;
}
void deleteMiddle(stack<int>&inputStack, int N)
{
    int mid = (N)/2;
    int count = 0;

    solve3000(inputStack, mid, count);

    return ;
}