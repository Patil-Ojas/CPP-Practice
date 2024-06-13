class Solution {
public:
    vector<int> nextSmallerElement(vector<int> &arr, int n)
    {
        // normal approach double loop
        stack<int> stck;
        vector<int> ans(n);
        stck.push(-1);

        for (int i=n-1; i>=0; i--)
        {
            int curr = arr[i];
            while (stck.top()!=-1 and arr[stck.top()] >= curr)
                stck.pop();
            
            ans[i] = stck.top();
            stck.push(i);
        }

        return ans;
    }
    vector<int> prevSmallerElement(vector<int> &arr, int n)
    {
        // normal approach double loop
        stack<int> stck;
        vector<int> ans(n);
        stck.push(-1);

        for (int i=0; i<n; i++)
        {
            int curr = arr[i];
            while (stck.top()!=-1 and arr[stck.top()] >= curr)
                stck.pop();
            
            ans[i] = stck.top();
            stck.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();

        vector<int>next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = -999;
        for (int i=0; i<n; i++)
        {
            if (next[i]==-1)
                next[i] = n;

            int l = heights[i];
            int b = next[i] - prev[i]-1;
            
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
};