class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return false;
        int left = 0, right = len - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) { return true; }
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) { left = mid + 1; }
                else                                             { right = mid - 1; }
            } else if (nums[mid] > nums[right]) {
                if (nums[left] <= target && nums[mid] > target) { right = mid - 1; }
                else                                            { left = mid + 1; }
            } else { --right; }
        }
        return false;
    }
};
