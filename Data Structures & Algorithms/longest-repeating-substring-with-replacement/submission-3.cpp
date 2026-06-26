class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int res = 0;
        unordered_map<char, int> count; // store freq of chars
        int maxf = 0;
        for (int r = 0; r < s.length(); r++) {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);
            while ((r - l + 1) - maxf > k) { // time to move window
                count[s[l]]--; // window is going to get moved, dont count this in next window now
                l++;
            }
            
            res = max(res, r - l + 1);
        }
        return res;
    }
};
