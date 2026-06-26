class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> s1;
        unordered_map<char, int> s2;
        for (int i = 0; i < s.length(); i++) {
            s1[s[i]]++;
            s2[t[i]]++;
        }
        return s1 == s2;
    }
};
