class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
       vector<vector<int>> res;
       vector<int> out;
       dfs(res, out, n, k, 0);
       return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& out, int n, int k, int level) {
        if (level == k) { res.push_back(out); return; }
        int start, end;
        if (out.size() == 0) start = 1;
        else start = out.back() + 1;
        end = n + 1 - (k - out.size() - 1);
        for (int i = start; i < end; ++i) {
            out.push_back(i);
            dfs(res, out, n, k, level + 1);
            out.pop_back();
        }
    }
};
