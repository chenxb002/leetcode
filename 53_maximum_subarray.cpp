class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();
        vector<int> dp(n, nums[0]);
        for (int i = 1; i < n; ++i) {
            dp[i] = (dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};
