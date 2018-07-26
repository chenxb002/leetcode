class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> temp;
        for (int i = 0; i < strs.size(); ++i) {
            string key = strs[i];
            sort(key.begin(), key.end());
            temp[key].push_back(strs[i]);
        }
        for (auto i : temp) {
            res.push_back(i.second);
        }
        return res;
    }
};
