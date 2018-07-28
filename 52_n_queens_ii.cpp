class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> pos(n, -1);
        dfs(pos, 0, res);
        return res;
    }
    void dfs(vector<int> &pos, int row, int &res) {
        int n = pos.size();
        if (row == n) { ++res; }
        else {
            for (int col = 0; col < n; ++col) {
                if (valid(pos, row, col)) {
                    pos[row] = col;
                    dfs(pos, row + 1, res);
                    pos[row] = -1;
                }
            }
        }
    }
    bool valid(vector<int> &pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (col == pos[i] || abs(row - i) == abs(col - pos[i])) {
                return false;
            }
        }
        return true;
    }
};
