class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxf = 0;
        unordered_map<char, int> charMap;
        int res = 0;
        for (int r = 0; r < s.length(); r++) {
            charMap[s[r]]++; // increase the frequency of the char
            maxf = max(maxf, charMap[s[r]]); // check what is the most frequent char so far
                                             // in our window
            if ((r - l + 1) - maxf > k) {   
                charMap[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};
