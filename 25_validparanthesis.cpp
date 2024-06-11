bool isValidParenthesis(string s)
{
    int len = s.length();
    int i=0;
    char temp;
    stack<char> stck;
    map<char, int> transform;

    transform['{'] = 1;
    transform['}'] = 1;

    transform['('] = 2;
    transform[')'] = 2;

    transform['['] = 3;
    transform[']'] = 3;

    while (len!=i)
    {
        temp = s[i];
        
        if (empty(stck) or transform[stck.top()] != transform[temp])
        {
            stck.push(temp);
        }
        else if (transform[stck.top()] == transform[temp])
        {
            stck.pop();
        }
        i++;
    }

    if (empty(stck))
        return true;
    else
        return false;
}