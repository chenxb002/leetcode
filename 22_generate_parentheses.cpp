class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return gp("", n, n);
    }
    vector<string> gp(string str, int left, int right) {
        if (left == right && left == 0) return {str};
        else if (left == right && left > 0) {
            return gp(str + '(', left - 1, right);
        } else if (left == 0) {
            return gp(str + ')', left, right - 1);
        } else {
            vector<string> res1 = gp(str + '(', left - 1, right);
            vector<string> res2 = gp(str + ')', left, right - 1);
            for (int i = 0; i < res2.size(); ++i) res1.push_back(res2[i]);
            return res1;
        }
    }
};
