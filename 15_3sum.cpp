class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) { continue; }
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int out = nums[i] + nums[j] + nums[k];
                if (out == 0) {
                    res.push_back({ nums[i], nums[j], nums[k] }); 
                    while (j < k && nums[j] == nums[j + 1]) { ++j; }
                    while (k > j && nums[k] == nums[k - 1]) { --k; }
                    ++j, --k;
                } else if (out > 0) {
                    --k;
                } else {
                    ++j;
                }   
            }   
        }   
        return res;
    }   
};
