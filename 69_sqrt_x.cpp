class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) { return 0; }
        int left = 1, right = x;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid * mid <= x && (mid + 1) * (mid + 1) > x) { return mid; }
            if (mid > x / mid) { right = mid; }
            else { left = mid; }
        }
    }
};
