class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       stack<int> st;
       heights.push_back(0);
       int res = 0;
       for (int i = 0; i < heights.size(); ++i) {
           while (!st.empty() && heights[st.top()] >= heights[i]) {
               int h = st.top();
               st.pop();
               res = max(res, heights[h] * (st.empty() ? i : (i - st.top() - 1)));
           }
           st.push(i);
       }
       return res;
    }
};


