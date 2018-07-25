class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> out;
        dps(candidates, 0, target, out, res);
        return res;
    }
    void dps(vector<int> &candidates, int start, int target, vector<int>& out, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) { res.push_back(out); return ; }
        for (int i = start; i < candidates.size(); ++i) {
          out.push_back(candidates[i]);
          dps(candidates, i, target - candidates[i], out, res);
          out.pop_back();
        }
    }
};
