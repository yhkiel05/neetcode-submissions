class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (string str : strs) {
            vector<int> counts (26, 0);
            for (int i = 0; i < str.length(); i++) {
                char c = str[i];
                counts[c - 'a']++;
            }
            string key = to_string(counts[0]);
            for (int i = 1; i < 26; i++) {
                key += ", " + to_string(counts[i]);
            }
            res[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};
