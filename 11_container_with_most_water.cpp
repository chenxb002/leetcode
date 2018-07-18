class Solution {
public:
    int maxArea(vector<int>& height) {
        size_t i = 0;
        size_t j = height.size() - 1;
        int maxsize = 0;
        while (i < j) {
            int curr = (j - i) * min(height[i], height[j]);
            maxsize = max(maxsize, curr);
            if (height[i] > height[j]) { --j; }
            else                       { ++i; }
        }
        return maxsize;
    }
};
