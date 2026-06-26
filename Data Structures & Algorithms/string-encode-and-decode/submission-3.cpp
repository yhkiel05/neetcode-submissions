class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (string s : strs) {
            res += to_string(s.length()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int start = 0;
        while (start < s.length()) {
            int j = start;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(start, j - start));
            start = j + 1;
            j = start + length;
            res.push_back(s.substr(start, length));
            start = j;
        }
        return res;
    }
};
