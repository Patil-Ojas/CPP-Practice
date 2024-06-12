#include <bits/stdc++.h> 

void sortedInsert(stack<int> &stck, int num)
{
	if (stck.empty() or (!stck.empty() and stck.top() < num))
	{
		stck.push(num);
		return ;
	}
	int temp = stck.top();
	stck.pop();

	sortedInsert(stck, num);

	stck.push(temp);
	return ;
}

void sortStack(stack<int> &stack)
{
	if (stack.empty())	
		return;
	
	int num = stack.top();
	stack.pop();

	sortStack(stack);

	sortedInsert(stack, num);

	return ;
}	