#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> stck;

    for (int i=0; i<s.length(); i++)
    {
        char ch = s[i];

        if (ch=='(' or ch=='+' or ch=='-' or ch=='*' or ch=='/')
        {
            stck.push(ch);
        }
        else
        {
            if (ch==')')
            {
                bool red_check = true;

                while (stck.top()!='(')
                {
                    char ch1 = stck.top();
                    if (ch1=='/' or ch1=='+' or ch1=='-' or ch1=='*')
                    {
                        red_check = false;
                    }
                    stck.pop();
                }

                if (red_check==true)
                {
                    return true;
                }
                stck.pop();
            }
        }
    }
    return false;
}
