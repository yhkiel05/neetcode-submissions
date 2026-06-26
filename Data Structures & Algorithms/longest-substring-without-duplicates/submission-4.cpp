class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_map<char,int> charMap;
        int maxLen = 0;
        for (int r = 0; r < s.length(); r++) {
            if (charMap.count(s[r]) && charMap[s[r]] >= l) {
                l = charMap[s[r]] + 1;
            } 
            charMap[s[r]] = r;
            int len = (r - l) + 1;
            maxLen = max(len, maxLen);
            
        }
        return maxLen;
    }
};
