class Solution {
public:
    int longestValidParentheses(string s) {
      int len = s.length();
      if (len <= 1) return 0;
      vector<int> lvp(len, 0);
      for (int i = 1; i < len; ++i) {
          if (s[i] == ')') {
              int j = i - 1;
              while (j >= 0 && lvp[j] != 0) {
                  j -= lvp[j];
              }
              if (j != -1 && s[j] == '(') {
                  lvp[i] = i - j + 1;
                  if (j > 0) { lvp[i] += lvp[j - 1]; }
              }
          }   
      }   
      int res = lvp[0];
      // for_each(lvp.begin(), lvp.end(), [int& res](const int& i) { res = max(res, i); });
      for (int i = 1; i < lvp.size(); ++i) {
          res = max(res, lvp[i]);
      }
      return res;
    }   
};
