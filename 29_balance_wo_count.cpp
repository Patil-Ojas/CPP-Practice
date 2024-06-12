#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  
  if (str.length()%2==1)
    return -1;
  
  stack<char> stck;

  for (int i=0; i<str.length(); i++)
  {
    if (stck.empty())
    {
      stck.push(str[i]);
    }

    if (str[i]=='{')
    {
      while (i<str.length())
      {
        if (str[i]=='}')
          stck.pop();
        else
          stck.push(str[i]);
        i++;

        if (stck.empty())
          break;
      }
    }
    
    if (str[i]=='}')
    {
      while (i<str.length())
      {
        if (str[i]=='{')
          stck.pop();
        else
          stck.push(str[i]);
        i++;

        if (stck.empty())
          break;
      }
    }
  }
  return stck.size()/2;
}