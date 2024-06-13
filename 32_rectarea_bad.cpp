// one apporach is bruteforce
// tihs shit sucks
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int area = 0;
        if (heights.size()==1)
            return heights[0];

        for (int i=0; i<heights.size(); i++)
        {
            int prev=i;
            int front=i;

            while (prev>=0 and heights[prev]>=heights[i])
                prev--;
            
            while (front<heights.size() and heights[front]>=heights[i])
                front++;

            int width=front-prev-1;
            // cout<<prev<<" "<<front<<" "<<width<<" ";
            int temp = width*heights[i];
            // cout<<temp<<endl;

            if (temp > area)
            {
                area = temp;    
            }
        }
        return area;
    }
};