class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int opt = abs(nums[0] + nums[1] + nums[2] - target);
        int value = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int diff = abs(nums[i] + nums[j] + nums[k] - target);
                if (opt > diff) { opt = diff; value = nums[i] + nums[j] + nums[k]; }
                if (abs(nums[i] + nums[j + 1] + nums[k] - target) > abs(nums[i] + nums[j] + nums[k - 1] - target)) {
                    --k;
                } else {
                    ++j;
                }   
            }   
        }   
        return value;
    }   
};
