#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
       if (n == 1) return "1";
       string prev_str = countAndSay(n - 1);
       cout << prev_str << endl;
       string str = "";
       int i = 1;
       int counter = 1;
       char c = prev_str[0];
       for (; i < prev_str.length(); ++i) {
           if (prev_str[i] == prev_str[i - 1]) {
               ++counter;
           } else {
             str = str + to_string(counter) + c;
             c = prev_str[i];
             counter = 1;
           }
       }
       str = str + to_string(counter) + c;
       return str;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(4) << endl;
    return 0;
}
