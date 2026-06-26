class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // find a way to group the anagrams;
        // char freq for each string
        // see which ones match
        unordered_map<string, vector<string>> map;
        for (string s : strs) {
            vector<int> freq(26, 0);

            for (char c : s) {
                freq[c - 'a']++;
            }
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(freq[i]) + "#";
            }
            map[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto pair: map) {
            res.push_back(pair.second);
        }
        return res;
    }
};
