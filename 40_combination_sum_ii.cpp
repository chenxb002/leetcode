class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> part_out;
        dps(candidates, 0, target, part_out, res);
        return res;
    }
    void dps(vector<int>& candidates, int start, int target, vector<int>& partial_out, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) { res.push_back(partial_out); return; }
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && num[i] == num[i - 1]) continue;
            partial_out.push_back(candidates[i]);
            dps(candidates, i + 1, target - candidates[i], partial_out, res);
            partial_out.pop_back();
        }
    }
};
