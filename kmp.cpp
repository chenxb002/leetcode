#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getNext(string pattern) {
    vector<int> next(pattern.length(), -1);
    next[0] = -1;
    int k = -1, j = 0;
    while (j < pattern.length() - 1) {
        if (k == -1 || pattern[j] == pattern[k]) {
            next[++j] = ++k;
        } else {
            k = next[k];
        }
    }
    return next;
}

int kmp(string src, string pattern) {
    int i = 0, j = 0;
    vector<int> next = getNext(pattern);
    int len_src = src.length();
    int len_pattern = pattern.length();
    while (i < len_src && j < len_pattern) {
        if (j == -1 || src[i] == pattern[j]) {
            ++i, ++j;
        } else {
            j = next[j];
        }
    }
    if (j == pattern.length()) {
        return i - j;
    } else {
        return -1;
    }
}

int main() {
    cout << kmp("abcvbabc", "cvb") << endl;
    return 0;
}
