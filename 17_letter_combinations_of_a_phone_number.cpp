#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string table[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return vector<string>(); 
        vector<string> temp = {""};
        return getlc(digits, 0, temp);
    }   

    vector<string> getlc(string digits, int depth, vector<string>& src) {
        if (depth == digits.length()) {
            return src;
        } else {
            int idx = digits[depth] - '0';
            vector<string> res;
            for (int i = 0; i < src.size(); ++i) {
                for (int j = 0; j < table[idx].length(); ++j) {
                    res.push_back(src[i] + table[idx][j]);
                }   
            }   
            return getlc(digits, depth + 1, res);
        }   
    }   
};

int main() {
  Solution s;
  s.letterCombinations("23");
}
