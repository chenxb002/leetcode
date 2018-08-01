class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) { return false; }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if (idx == word.length()) return true;
        if (i < 0 || i >= board.size()
            || j < 0 || j >= board[0].size()
            || board[i][j] != word[idx]) return false;
        char temp = board[i][j];
        board[i][j] = '#';
        bool res =  dfs(board, word, i + 1, j, idx + 1)
                    || dfs(board, word, i - 1, j, idx + 1)
                    || dfs(board, word, i, j + 1, idx + 1)
                    || dfs(board, word, i, j - 1, idx + 1);
        board[i][j] = temp;
        return res;
    }
};
