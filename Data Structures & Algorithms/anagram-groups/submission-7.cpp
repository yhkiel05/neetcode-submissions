class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        for (string s : strs) {
            vector<int> charFreq(26, 0);
            for (char c : s) {
                charFreq[c - 'a']++;
            }
            string key = "" + to_string(charFreq[0]);
            for (int i = 1; i <= 26; i++) {
                key += "," + to_string(charFreq[i]);
            }
            anagramMap[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto pair : anagramMap) {
            res.push_back(pair.second);
        }
        return res; 
    }
};
