class Solution {
public:
    bool canJump(vector<int>& nums) {
       int len = nums.size();
       int curr = 0, ex = max(0, nums[curr]);
       while ((ex < len - 1) && (curr < ex || (curr == ex && nums[ex] != 0))) {
           ex = max(ex, curr + nums[curr]);
           ++curr;
       }
       if (ex >= len - 1) { return true; }
       return false;
    }
};
