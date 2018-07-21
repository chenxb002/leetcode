class Solution {
public:
    int divide(int dividend, int divisor) {
        long long m = abs((long long) dividend); 
        long long n = abs((long long) divisor); 
        long long res = 0;
        while (m >= n) {
            long long p_sum = 1, n_tmp = n;
            while (m > (n_tmp << 1)) {
                n_tmp <<= 1;
                p_sum <<= 1;
            }
            res += p_sum;
            m -= n_tmp;
        }
        if ((dividend < 0) ^ (divisor < 0)) {
            res = 0 - res;
        }
        if (res > INT_MAX) {
            return INT_MAX;
        }
        return res;
    }
};
