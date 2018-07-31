class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return ;
        int first = 0, last = n - 1;
        for (int i = 0; i <= last; ++i) {
            while (nums[i] == 2 && i < last) { swap(nums[i], nums[last--]); }
            while (nums[i] == 0 && i > first) { swap(nums[i], nums[first++]); }
        }
    }
};
