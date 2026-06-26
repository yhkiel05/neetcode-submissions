class Solution {
public:
    int characterReplacement(string s, int k) {
        // we only want to replace for the most freq character
        // find the most freq char first
        // ABABBA k = 2, can replace either a or b
        // windowlen - count[b] = 4 -3 = 1 <= k
        // this is the almost optimal solution
        unordered_map<char, int> map;
        int l = 0;
        int res = 0;
        int maxfreq = 0;
        for (int r = 0; r < s.length(); r++) {
            map[s[r]]++;
            maxfreq = max(map[s[r]], maxfreq);
            while ((r - l + 1) - maxfreq > k) {
                map[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
        
    }
};
