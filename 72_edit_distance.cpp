class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> diff(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m + 1; ++i) {
            diff[i][0] = i;
        }
        for (int i = 0; i < n + 1; ++i) {
            diff[0][i] = i;
        }
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (word1[i - 1] == word2[j - 1]) { diff[i][j] = diff[i - 1][j - 1]; continue; }
                diff[i][j] = 1 + min(diff[i - 1][j - 1], min(diff[i - 1][j], diff[i][j - 1]));
            }
        }
        return diff[m][n];
    }
};
