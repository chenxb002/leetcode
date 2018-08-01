#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int s_len = s.length(), t_len = t.length();
        if (s_len < t_len) { return ""; }
        unordered_map<char, int> pattern_cnt;
        for (int i = 0; i < t_len; ++i) {
            if (pattern_cnt.find(t[i]) == pattern_cnt.end()) { pattern_cnt[t[i]] = 1; }
            else                                             { ++pattern_cnt[t[i]]; }
        }
        int len = s_len + 1;
        int left = 0, right = 0, count = 0;
        string res = "";
        for (int right = 0; right < s_len; ++right) {
            if (pattern_cnt.find(s[right]) == pattern_cnt.end()) { continue; }
            --pattern_cnt[s[right]];
            if (pattern_cnt[s[right]] >= 0) { ++count; }
            while (count == t_len) {
                if (right - left + 1 < len) {
                    len = right - left + 1;
                    res = s.substr(left, len);
                }
                if (pattern_cnt.find(s[left]) != pattern_cnt.end()) {
                    ++pattern_cnt[s[left]];
                    if (pattern_cnt[s[left]] > 0) { --count; }
                }
                ++left;
            }
        }
        return res;
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution S;
    cout << S.minWindow(s, t) << endl;
    return 0;
}
