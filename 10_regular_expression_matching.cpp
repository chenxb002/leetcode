class Solution {
public:
    bool isMatch(string s, string p) {
        size_t len_s = s.length();
        size_t len_p = p.length();
        vector<vector<bool>> dp(len_s + 1, vector<bool>(len_p + 1, false));
        for (size_t i = 0; i < len_s + 1; ++i) {
            for (size_t j = 0; j < len_p + 1; ++j) {
                if (j == 0) { dp[i][j] = (i == 0); }
                else if (j >= 2 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i >= 1 && equal(s[i - 1], p[j - 2]) && dp[i - 1][j]);
                } else {
                    dp[i][j] = (i >= 1) && equal(s[i - 1], p[j - 1]) && dp[i - 1][j - 1];
                }
            }  // for j
        }  // for i
        return dp[len_s][len_p];
    }  // isMatch
    bool equal(char a, char b) {
        if (a == b || b == '.') {
            return true;
        }  // if a
        return false;
    }  // equal
};
