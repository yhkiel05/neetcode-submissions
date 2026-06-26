class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int maxLen = 0;
        unordered_set<char> charSet;
        for (int r = 0; r < s.length(); r++) {
            while (charSet.count(s[r])) {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            int len = (r - l) + 1;
            maxLen = max(maxLen, len);  
        }
        return maxLen;
    }
};
