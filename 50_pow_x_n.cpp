class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) { return 1; }
        if (n < 0 && n > INT_MIN) { x = 1/x; n = -n; }
        return (n % 2 == 0) ? pow(x * x, n / 2) : x * pow(x * x, n / 2);
    }
};
