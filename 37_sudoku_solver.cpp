class Solution {
public:
    bool valid(vector<vector<char>>& board) {
        vector<int> counter(9, 0);
        for (int i = 0; i < 9; ++i) {
            counter.assign(9, 0);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                if (++counter[board[i][j] - '1'] > 1) {
                    return false;
                }            
            }                
        }
        for (int i = 0; i < 9; ++i) {
            counter.assign(9, 0);
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.') continue;
                if (++counter[board[j][i] - '1'] > 1) {
                    return false;
                }
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                counter.assign(9, 0);
                for (int m = 0; m < 3; ++m) {
                    for (int n = 0; n < 3; ++n) {
                        if (board[i * 3 + m][j * 3 + n] == '.') continue;
                        if (++counter[board[i * 3 + m][j * 3 + n] - '1'] > 1) {
                            return false;
                        }
                    }               
                }                   
            }
        }
        return true;
    }
    
    bool solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int k = 1; k < 10; ++k) {
                        board[i][j] = '0' + k;
                        if (valid(board) && solveSudoku(board)) {
                            return true;
                        }   
                        board[i][j] = '.';
                    }   
                    return false;
                }   
            }   
        }   
        return true;
    }   
};
