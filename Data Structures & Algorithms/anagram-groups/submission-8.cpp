class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> freq;
        for (string s : strs) {
            vector<int> count(26,0);
            for (int i = 0; i < s.length(); i++) {
                count[s[i] - 'a']++;
            }
            string key = "";
            for (int i = 0; i < count.size(); i++) {
                key = key + to_string(count[i]) + ",";
            }
            freq[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto pair : freq) {
            res.push_back(pair.second);
        }
        return res;

    }
};
