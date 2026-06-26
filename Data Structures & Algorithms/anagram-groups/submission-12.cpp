class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> anagrams;
        
        for (int i = 0; i < strs.size(); i++) {
            vector<int> count(26, 0);
            for (char s : strs[i]) {
                count[s - 'a']++;
            }
            
            // Build the unique key string (e.g., "1#0#1#...")
            string key = "";
            for (int j = 0; j < 26; j++) {
                // Using a delimiter like '#' prevents ambiguity (e.g., 1 and 11 vs 11 and 1)
                key += to_string(count[j]) + "#"; 
            }
            
            // C++ unordered_map automatically creates the entry if it doesn't exist
            anagrams[key].push_back(strs[i]);
        }
        
        // Corrected structured binding syntax (requires auto)
        for (auto& [key, value] : anagrams) {
            res.push_back(value);
        }
        
        return res;
    }
};