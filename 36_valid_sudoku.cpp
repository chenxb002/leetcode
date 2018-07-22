class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> ct;
        for (int i = 0; i < 9; ++i) {
            ct.assign(10, 0);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int idx = board[i][j] - '0';
                if ((++ct[idx]) > 1) {
                  return false;
                }
            }
        }
        for (int i = 0; i < 9; ++i) {
            ct.assign(10, 0);
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.') continue;
                int idx = board[j][i] - '0';
                if ((++ct[idx]) > 1) {
                  return false;
                }
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                ct.assign(10, 0);
                for (int m = 0; m < 3; ++m) {
                    for (int n = 0; n < 3; ++n) {
                        if (board[i * 3 + m][j * 3 + n] == '.') continue;
                        int idx = board[i * 3 + m][j * 3 + n] - '0';
                        if ((++ct[idx]) > 1) {
                          return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
