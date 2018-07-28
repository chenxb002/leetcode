class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.length() - 1;
        while (i != -1 && s[i] == ' ') --i;
        while (i != -1 && s[i] != ' ') { --i; ++len; }
        return len;
    }
};
