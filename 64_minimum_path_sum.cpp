class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        res[0][0] = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) { res[i][j] = min(res[i][j], res[i - 1][j]); }
                if (j > 0) { res[i][j] = min(res[i][j], res[i][j - 1]); }
                res[i][j] += grid[i][j];
            }
        }
        return res[m - 1][n - 1];
    }
};
