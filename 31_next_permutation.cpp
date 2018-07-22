class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        if (!nextp(nums, nums.size() - 2)) {
            reverse(nums.begin(), nums.end());
        }
    }

    bool nextp(vector<int>& nums, int start) {
        if (start == -1) return false;
        if (nums[start] < nums[start + 1]) {
            int i;
            for (i = start + 1; i < nums.size(); ++i) {
                if (nums[start] < nums[i] && (i + 1 == nums.size() || nums[start] >= nums[i + 1])) {
                    break;
                }
            }
            swap(nums[start], nums[i]);
            reverse(next(nums.begin(), start + 1), nums.end());
            return true;
        } else {
            return nextp(nums, start - 1);
        }
    }
};
