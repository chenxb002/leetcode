class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        if (matrix.empty() || matrix[0].empty()) { return res; }
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
               if (i == 0) { matrix[i][j] -= '0'; }
               if (i != 0) {
                   matrix[i][j] = (matrix[i][j] == '0' ? 0 : matrix[i][j] - '0' + matrix[i - 1][j]);
               }
            }
            res = max(largestRectangleArea(matrix[i]), res);
        }
        return res;
    }

    int largestRectangleArea(vector<char>& heights) {
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
