class Solution {
public:
    string simplifyPath(string path) {
        string res;
        stringstream ss(path);
        stack<string> elems;
        string temp;
        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".") { continue; }
            if (temp == "..") {
                if (!elems.empty()) {
                    elems.pop();
                }
                continue;
            } else {
                elems.push(temp);
            }
        }
        if (elems.empty()) { return "/"; }
        while (!elems.empty()) {
            res = '/' + elems.top() + res;
            elems.pop();
        }
        return res;
    }
};
