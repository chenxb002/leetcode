class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) { len++; continue; }
            if (nums[i] != nums[len - 1]) {
                nums[len] = nums[i];
                ++len;
            }
        }
        return len;
    }
};
