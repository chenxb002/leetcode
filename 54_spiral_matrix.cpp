class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return vector<int>();
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int outer_loop = min((m + 1) /2, (n + 1) / 2);
        for (int i = 0; i < outer_loop; ++i) {
            for (int j = i; j < n - i; ++j) {
                res.push_back(matrix[i][j]);
            }
            for (int j = i + 1; j < m - i; ++j) {
                res.push_back(matrix[j][n - i - 1]);
            }
            if (i == m - i - 1 || n - i - 1 == i) {
                break;
            }
            for (int j = n - i - 2; j >= i; --j) {
                res.push_back(matrix[m - i - 1][j]);
            }
            for (int j = m - i - 2; j > i; --j) {
                res.push_back(matrix[j][i]);
            }
        }
        return res;
    }
};
