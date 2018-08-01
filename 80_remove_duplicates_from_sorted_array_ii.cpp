class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) { return len; }
        int idx = 0, cnt = 1;
        for (int i = 1; i < len; ++i) {
            if (nums[i] == nums[i - 1]) { ++cnt; }
            else                        { cnt = 1; }
            if (cnt <= 2) { nums[++idx] = nums[i]; }
        }
        return idx + 1;
    }
};
