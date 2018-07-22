class Solution {
public:
    int longestValidParentheses(string s) {
      int len = s.length();
      stack<int> left;
      int maxlen = 0;
      int valid_index = 0;
      for (int i = 0; i < len; ++i) {
        if (s[i] == '(') { left.push(i); }
        else {
            if (left.empty()) { valid_index = i + 1; }
            else {
                left.pop();
                if (left.empty()) { maxlen = max(maxlen, i - valid_index + 1); }
                else              { maxlen = max(maxlen, i - left.top());      }
            }
        }
      }
      return maxlen;
    }   
};
