class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // store the results with a frequency array as the key
        unordered_map<string, vector<string>> anagrams;
        for (string s : strs) {
            vector<int> freq(26, 0);
            for (char c: s) {
                freq[c - 'a']++;
            }
            string key = "" + to_string(freq[0]);
            for (int i = 1; i < 26; i++) {
                key = key + "," + to_string(freq[i]);
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
