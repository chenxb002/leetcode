class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool add_one = true;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (!add_one) { break; }
            if (digits[i] != 9) { add_one = false; }
            digits[i] = (digits[i] + 1) % 10;
        }
        if (add_one) { digits.insert(digits.begin(), 1); }
        return digits;
    }
};
