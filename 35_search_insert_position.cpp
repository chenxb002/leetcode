class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        if (nums[j] < target) { return j + 1; }
        int pos = 0;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] >= target && (mid == 0 || nums[mid - 1] < target)) {
                pos = mid;
                break;
            }
            if (nums[mid] > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return pos;
    }
};
