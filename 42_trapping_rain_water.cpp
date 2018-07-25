class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> left(len, 0);
        vector<int> right(len, 0);
        int res = 0;
        for (int i = 0; i < len; ++i) {
            if (i != 0) left[i] = max(left[i - 1], height[i - 1]);
        }
        for (int i = len - 1; i >= 0; --i) {
            if (i != len - 1) right[i] = max(right[i + 1], height[i + 1]);
        }
        for (int i = 0; i < len; ++i) {
            res += max(min(left[i], right[i]) - height[i], 0);
        }
        return res;
    }
};
