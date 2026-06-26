class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (string s : strs) {
            vector<int> freq(26,0);
            for (char c : s) {
                freq[c - 'a']++;
            }
            string key = "";
            for (int n : freq) {
                key = key + to_string(n) + ",";
            }
            anagrams[key].push_back(s);
        } 
        vector<vector<string>> res;
        for (auto pair : anagrams) {
            res.push_back(pair.second);
        }
        return res;
    }
};
