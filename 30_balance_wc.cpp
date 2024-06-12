#include <bits/stdc++.h> 

int findMinimumCost(string str) {

    int n = str.size();

  stack<int> st;

  if(n%2 == 1) return -1;

  for(int i=0;i<n;i++){

      if(str[i] == '{'){

          st.push(str[i]);

        }

      else{

          if (!st.empty() && st.top() == '{') {

            st.pop();

          } else

            st.push(str[i]);

        }

  }

  int open  = 1, close = 1;

  while(!st.empty()){

      if(st.top() == '{'){

          open++;

      }

      else close++;

      st.pop();

  }

  return (open/2) + (close/2);

}