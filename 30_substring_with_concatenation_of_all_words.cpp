class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int words_size = words.size();
        vector<int> res;
        if (words_size == 0) return res;

        map<string, int> word_count;
        int word_size = words[0].length();
        for (int i = 0; i < words_size; ++i) {
            ++word_count[words[i]];
        }
        map<string, int> counting;
        for (int i = 0; i <= (int)s.length() - words_size * word_size; ++i) {
            counting.clear();
            int j;
            for (j = 0; j < words_size; ++j) {
                string word = s.substr(i + j * word_size, word_size);
                if (word_count.find(word) != word_count.end()) {
                    ++counting[word];
                    if (counting[word] > word_count[word]) {
                        break;
                    }
                } else {
                    break;
                }
            }
            if (j == words_size) {
                res.push_back(i);
            }
        }
        return res;
    }
};
