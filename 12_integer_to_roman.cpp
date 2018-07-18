class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        char symbol[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
        int unit[] = { 1, 5, 10, 50, 100, 500, 1000 };
        for (int i = 7; i >= 0; --i) {
            int temp_num = num / unit[i];
            num = num % unit[i];
            if (i % 2 == 0 && temp_num == 4) {
                res = res + string(unit[i + 1]) + string(unit[i]);
            } else {
                res = res + temp_num * unit[i];
            }
        }
        return res;
    }
};
