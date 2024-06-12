void solve9000(stack<int> &stck, int x, int &n)
{
    if (n==0)
    {
        stck.push(x);
        return ;
    }

    int temp = stck.top();
    stck.pop();
    n--;
    solve9000(stck, x, n);
    stck.push(temp);
    return ;
}

void solve3000(stack<int>&stck, int &k)
{
    if (k==0)
        return ;
    
    int temp = stck.top();
    stck.pop();
    --k;
    solve3000(stck, k);

    int leng = stck.size();
    solve9000(stck, temp, leng);
    return ;    
}

void reverseStack(stack<int> &stack) {
    int k = stack.size();
    solve3000(stack, k);

    return ;
}