class Solution {
public:
    int strStr(string haystack, string needle) {
        int s_len = haystack.length();
        int p_len = needle.length();
        if (p_len == 0) { return 0; }
        int i = 0, j = 0;
        vector<int> next = getNext(needle);
        while (i < s_len && j < p_len) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i, ++j;
            } else {
                j = next[j];
            }
        }
        if (j == p_len) {
            return i - j;
        }
        return -1;
    }

    vector<int> getNext(string p) {
      int len = p.length();
      vector<int> next(len, -1);
      int k = -1, j = 0;
      while (j < len - 1) {
          if (k == -1 || p[k] == p[j]) {
              next[++j] = ++k;
          } else {
              k = next[k];
          }
      }
      return next;
    }
};
